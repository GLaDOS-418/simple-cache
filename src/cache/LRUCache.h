#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <string>
#include <memory>

#include "ICache.h"

namespace cache {

    using Key = std::string;
    using Value = std::string;

    class LRUCache : public cache::ICache<Key, Value> {
    public :

        Status put( const Key&, const Value& ) override;
        std::tuple<Status, Value> get( const Key& ) const override;

    private:
        struct LRUCacheImpl;
        std::unique_ptr<LRUCacheImpl> pImpl;
    };
}


#endif // !LRUCACHE_H
