#ifndef CacheController_h
#define CacheController_h

#include <iostream>

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "dto/RetrieveEntryDto.h"
#include "dto/AddEntryDto.h"

#include "CacheProxy.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CacheController : public oatpp::web::server::api::ApiController {
    controller::CacheProxy m_cacheProxy;
public:

  CacheController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
public:
  
  ENDPOINT("GET", "/cache", getValue, 
      QUERY( String, key, "key" )
      ) {
        OATPP_LOGD("get | ", "key=%s", key->getData() );
        return createDtoResponse( Status::CODE_200, m_cacheProxy.get( key->std_str( ) ) );
  }
  
  
  ENDPOINT("PUT", "/cache", putValue,
      BODY_DTO( Object<dto::AddEntryReqDto>, entryDto )
      ) {
        OATPP_LOGD("put | ", "key=%s, value=%s", entryDto->key->getData(), entryDto->value->getData() );
        return createDtoResponse( Status::CODE_200, m_cacheProxy.put( entryDto->key->std_str( ), entryDto->value->std_str( ) ) );
  }

};

#include OATPP_CODEGEN_END(ApiController)

#endif /* CacheController_h */
