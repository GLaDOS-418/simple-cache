#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <tuple>

#include "oatpp/core/Types.hpp"

namespace cache {

    enum Status : uint16_t {
        FOUND = 0,   // requested value for a key found
        NOTFOUND, // key does not exist
        NEW,     // new entry added in cache
        UPDATE,  // value updated
        INVALID, // invalid request, request denied/dropped
        ERROR
    };

    using Key = oatpp::String;
    using Value = oatpp::String;

    //using Key = std::string;
    //using Value = std::string;

    class ICache {
    public:
        virtual std::tuple<Status, Value> get( const Key& ) const = 0;
        virtual Status put( const Key&, const Value& ) = 0;
    };
}

#endif // !CACHE_H
