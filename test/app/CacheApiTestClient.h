
#ifndef MyApiTestClient_hpp
#define MyApiTestClient_hpp

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "dto/AddEntryDto.h"

/* Begin Api Client code generation */
#include OATPP_CODEGEN_BEGIN(ApiClient)

class CacheApiTestClient : public oatpp::web::client::ApiClient {

    API_CLIENT_INIT( CacheApiTestClient );

    // get value of an entry
    API_CALL( "GET", "/cache", getValue, QUERY( String, key ) );

    // add a key value pair to the cache
    API_CALL( "PUT", "/cache", putValue, BODY_DTO( Object<dto::AddEntryReqDto>, kvPair) );

};

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)

#endif // MyApiTestClient_hpp
