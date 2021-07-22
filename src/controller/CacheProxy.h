#ifndef CACHEPROXY_H
#define CACHEPROXY_H

#include <memory>

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "../cache/ICache.h"
#include "../dto/AddEntryDto.h"
#include "../dto/RetrieveEntryDto.h"

namespace controller {

    class CacheProxy {

        OATPP_COMPONENT( std::shared_ptr<cache::ICache>, m_cache );

    public:
        auto get( const cache::Key& key ) {
            auto [status, value] = m_cache->get( key );

            auto dto = dto::RetrieveEntryResDto::createShared( );
            dto->statusCode = status;
            dto->value = value;

            return dto;
        }

        auto put( const cache::Key& key, const cache::Value& val ) {
            auto status = m_cache->put( key, val );

            auto dto = dto::AddEntryResDto::createShared( );
            dto->statusCode = status;

            return dto;
        }

    };
}
#endif // !CACHEPROXY_H
