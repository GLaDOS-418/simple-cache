#include "CacheControllerTest.h"

#include "controller/CacheController.h"

#include "app/CacheApiTestClient.h"
#include "app/TestComponent.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"

#include "oatpp-test/web/ClientServerTestRunner.hpp"

namespace tests {
    void CacheControllerTest::onRun( ) {

        /* Register test components */
        TestComponent component;

        /* Create client-server test runner */
        oatpp::test::web::ClientServerTestRunner runner;

        /* Add CacheController endpoints to the router of the test server */
        runner.addController( std::make_shared<CacheController>( ) );

        /* Get client connection provider for Api Client */
        OATPP_COMPONENT( std::shared_ptr<oatpp::network::ClientConnectionProvider>, clientConnectionProvider );

        /* Get object mapper component */
        OATPP_COMPONENT( std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper );

        /* Create http request executor for Api Client */
        auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared( clientConnectionProvider );

        /* Create Test API client */
        auto client = CacheApiTestClient::createShared( requestExecutor, objectMapper );

        /* TEST 1 - get value | not found */
        runner.run( [&] {

            /* Call server API */
            auto response = client->getValue( "foo" );

            /* Assert that server responds with 200 */
            OATPP_ASSERT( response->getStatusCode( ) == 200 );

            /* Read response body as MessageDto */
            auto message = response->readBodyToDto<oatpp::Object<dto::RetrieveEntryResDto>>( objectMapper.get( ) );

            /* Assert that received message is as expected */
            OATPP_ASSERT( message );
            OATPP_ASSERT( message->statusCode == 200 );
            OATPP_ASSERT( message->value == "bar" );
            /* END TEST 1*/
        }, std::chrono::seconds( 20 ) /* test timeout */ );
        /* TEST 2 - put value | new value */
        runner.run( [&] {

            /* Call server API */
            auto response = client->getValue( "foo" );

            /* Assert that server responds with 200 */
            OATPP_ASSERT( response->getStatusCode( ) == 200 );

            /* Read response body as MessageDto */
            auto message = response->readBodyToDto<oatpp::Object<dto::RetrieveEntryResDto>>( objectMapper.get( ) );

            /* Assert that received message is as expected */
            OATPP_ASSERT( message );
            OATPP_ASSERT( message->statusCode == 200 );
            OATPP_ASSERT( message->value == "bar" );
            /* END TEST 1*/
        }, std::chrono::seconds( 20 ) /* test timeout */ );

        /* TEST 3 - get value | found */
        runner.run( [&] {

            /* Call server API */
            auto response = client->getValue( "foo" );

            /* Assert that server responds with 200 */
            OATPP_ASSERT( response->getStatusCode( ) == 200 );

            /* Read response body as MessageDto */
            auto message = response->readBodyToDto<oatpp::Object<dto::RetrieveEntryResDto>>( objectMapper.get( ) );

            /* Assert that received message is as expected */
            OATPP_ASSERT( message );
            OATPP_ASSERT( message->statusCode == 200 );
            OATPP_ASSERT( message->value == "bar" );
            /* END TEST 1*/
        }, std::chrono::seconds( 20 ) /* test timeout */ );

        /* TEST 4 - put value | update */

        runner.run( [&] {

            /* Call server API */
            auto response = client->getValue( "foo" );

            /* Assert that server responds with 200 */
            OATPP_ASSERT( response->getStatusCode( ) == 200 );

            /* Read response body as MessageDto */
            auto message = response->readBodyToDto<oatpp::Object<dto::RetrieveEntryResDto>>( objectMapper.get( ) );

            /* Assert that received message is as expected */
            OATPP_ASSERT( message );
            OATPP_ASSERT( message->statusCode == 200 );
            OATPP_ASSERT( message->value == "bar" );
            /* END TEST 1*/
        }, std::chrono::seconds( 20 ) /* test timeout */ );
        /* TEST 5 - put value | request denied, malformed key */

        runner.run( [&] {

            /* Call server API */
            auto response = client->getValue( "foo" );

            /* Assert that server responds with 200 */
            OATPP_ASSERT( response->getStatusCode( ) == 200 );

            /* Read response body as MessageDto */
            auto message = response->readBodyToDto<oatpp::Object<dto::RetrieveEntryResDto>>( objectMapper.get( ) );

            /* Assert that received message is as expected */
            OATPP_ASSERT( message );
            OATPP_ASSERT( message->statusCode == 200 );
            OATPP_ASSERT( message->value == "bar" );
            /* END TEST 1*/
        }, std::chrono::seconds( 20 ) /* test timeout */ );
        /* TEST 6 - get value | request denied, malformed key */
        runner.run( [&] {

            /* Call server API */
            auto response = client->getValue( "foo" );

            /* Assert that server responds with 200 */
            OATPP_ASSERT( response->getStatusCode( ) == 200 );

            /* Read response body as MessageDto */
            auto message = response->readBodyToDto<oatpp::Object<dto::RetrieveEntryResDto>>( objectMapper.get( ) );

            /* Assert that received message is as expected */
            OATPP_ASSERT( message );
            OATPP_ASSERT( message->statusCode == 200 );
            OATPP_ASSERT( message->value == "bar" );
            /* END TEST 1*/
        }, std::chrono::seconds( 20 ) /* test timeout */ );

        /* wait all server threads finished */
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );

    }
}
