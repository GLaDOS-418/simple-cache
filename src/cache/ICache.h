#ifndef CACHE_H
#define CACHE_H

#include <cstring>
#include <string>
#include <tuple>

#include "oatpp/core/Types.hpp"

namespace cache {

    enum Status : uint16_t {
        FOUND =  0,   // requested value for a key found
        NOTFOUND = 1, // key does not exist
        NEW = 2,      // new entry added in cache
        UPDATE = 3,   // value updated
        INVALID = 4,  // invalid request, request denied/dropped
        ERROR = 5
    };

    //using Key = oatpp::String;
    //using Value = oatpp::String;

    using Key = std::string;
    using Value = std::string;

    class ICache {
    public:
        virtual [[nodiscard]] std::tuple<Status, Value> get( const Key& ) const = 0;
        virtual [[nodiscard]] Status put( const Key&, const Value& ) = 0;
    };
}

#endif // !CACHE_H
