#include "LRUCache.h" 

#include <unordered_map>
#include <atomic>
#include <shared_mutex>

namespace cache {

    LRUCache::LRUCache( ) : pImpl{ std::make_shared <LRUCache::LRUCacheImpl>( ) } {}

    struct LRUCache::LRUCacheImpl {
    private:
        struct List {

            struct Node {
                Key key;
                Node* next = nullptr;
                Node* prev = nullptr;

                Node( const Key& k ) : key{ k } { }
                ~Node( ) = default;
            };


        private:
            Node* start = nullptr;
            Node* end = nullptr;
            std::atomic<int> cacheSize;

        public:
            Node* addNode( const Key& key ) {
                try {
                    if ( nullptr == start && nullptr == end ) {
                        start = new Node( key );
                        end = start;
                    }

                    auto temp = new Node( key );
                    end->next = temp;
                    temp->prev = end;
                    end = temp;

                    ++cacheSize;

                    return end;
                }
                catch ( std::exception& ) {
                    // very generic exception. could be improved.
                }

                return nullptr;
            }

            void useNode( Node* entryUsed ) {
                try {
                    if ( entryUsed ) {
                        auto prev = entryUsed->prev;
                        auto nxt = entryUsed->next;

                        if ( prev )
                            prev->next = entryUsed->next;
                        if ( nxt )
                            nxt->prev = entryUsed->prev;

                        end->next = entryUsed;
                        entryUsed->prev = end;
                        entryUsed->next = nullptr;
                        end = entryUsed;
                    }
                }
                catch ( std::exception& ) {
                    // very broad exception catch
                }
            }

            Key deleteFront( ) {
                try {
                    if ( start ) {
                        auto key = start->key;
                        start = start->next;
                        start->prev = nullptr;

                        --cacheSize;
                        return key;
                    }
                }
                catch ( std::exception& ) {
                    // very broad exception catch
                }

                return Key{};
            }

            Key deleteNode( Node* node ) {
                if ( node ) {
                    auto key = node->key;
                    auto prev = node->prev;
                    auto next = node->next;

                    if ( prev )
                        prev->next = next;
                    if ( next )
                        next->prev = prev;
                    return key;
                }

                return Key{};
            }
        };

        struct Entry {
            Value m_value;
            List::Node* m_usedOrder;
        };


        std::unordered_map<Key, Entry> m_data;
        List m_recentlyUsed;

        std::shared_mutex rw_lock;

    private:
        // utility functions, don't acquire locks

        bool isCacheFull( ) {
            // TODO : this should be something determined by the environment, probably available memory
            return false;
        }

        void evictOldest( ) {
            // remove from front
            m_data.erase( m_recentlyUsed.deleteFront( ));
        }

        void evictKey( const Key& key ) {
            // better to use the iterator from prev search, saves extra search
            auto entry = m_data.find( key );
            if ( m_data.end( ) != entry ) {
                m_recentlyUsed.deleteNode( (entry->second).m_usedOrder );
                m_data.erase( key );
            }
        }

        bool isExpired( const Entry& e ) {
            // this should be used as validating TTL
            return false;
        }

    public:

        // these operations are not ACI(D) compliant
        // could be made so in the future

        Status put( const Key& key, const Value& val ) {
            // acquire write lock - raii
            try {
                auto entry = m_data.find( key );
                if ( m_data.end( ) != entry ) {
                    (entry->second).m_value = val;
                    m_recentlyUsed.useNode( (entry->second).m_usedOrder );

                    return Status::UPDATE;
                }
                else {
                    if ( isCacheFull( ) ) {
                        evictOldest( );
                    }
                    m_data.emplace( key, Entry{ val, m_recentlyUsed.addNode( key ) } );

                    return Status::NEW;
                }
            }
            catch ( std::exception& ) {
                // TODO
            }

            return Status::ERROR;
        }

        std::tuple<Status, Value> get( const Key& key ) {
            // acquire read lock - raii

            try {
                auto entry = m_data.find( key );
                if ( m_data.end( ) != entry ) {
                    if ( isExpired( entry->second ) ) {
                        evictKey( entry->first );

                        return { Status::NOTFOUND, Value{} /*empty value object*/ };
                    }

                    m_recentlyUsed.useNode( (entry->second).m_usedOrder );
                    return { Status::FOUND, (entry->second).m_value };
                }

                return { Status::NOTFOUND, Value{} };
            }
            catch ( std::exception& ) {
                // TODO
            }

            return { Status::ERROR, Value{} };
        }

    };


    Status LRUCache::put( const Key& k, const Value& v ) {
        return pImpl->put( k, v );
    }

    std::tuple<Status, Value> LRUCache::get( const Key& k ) const {
        return pImpl->get( k );
    }
}