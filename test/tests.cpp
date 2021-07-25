
#include "CacheControllerTest.h"

#include <iostream>

void runTests( ) {
    // run tests
    OATPP_RUN_TEST( tests::CacheControllerTest );

}

int main( ) {

    // init env
    oatpp::base::Environment::init( );

    runTests( );

    // clean up env
    oatpp::base::Environment::destroy( );

    return 0;
}
