#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <string>
#include <memory>

#include "ICache.h"

namespace cache {

    class LRUCache : public cache::ICache {
    public :

        Status put( const Key&, const Value& ) override;
        std::tuple<Status, Value> get( const Key& ) const override;

        LRUCache( );
        ~LRUCache( ) = default;

        LRUCache( const LRUCache& ) = delete;
        LRUCache& operator=( const LRUCache& ) = delete;
        LRUCache( LRUCache&& ) = delete;
        LRUCache&& operator=( LRUCache&& ) = delete;

    private:
        struct LRUCacheImpl;
        std::shared_ptr<LRUCacheImpl> pImpl;
    };
}


#endif // !LRUCACHE_H
