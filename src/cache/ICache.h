#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <tuple>

namespace cache {

    enum class Status {
        INVALID, // invalid request, request denied/dropped
        UPDATE,  // value updated
        NEW,     // new entry added in cache
        FOUND,   // requested value for a key found
        NOTFOUND, // key does not exist
        ERROR
    };

    template< class K = std::string, class V = std::string >
    class ICache {
    public:
        virtual std::tuple<Status, V> get( const K& ) const = 0;
        virtual Status put( const K&, const V& ) = 0;

        virtual ~ICache( ) = default;

        //protected:
        //    virtual bool isFull( ) const = 0;
        //    virtual void evictEntry( ) = 0;
        //    virtual bool isExpired( const K& ) const = 0;
    };
}

#endif // !CACHE_H
