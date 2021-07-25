#ifndef MyControllerTest_hpp
#define MyControllerTest_hpp

#include "oatpp-test/UnitTest.hpp"

namespace tests {

    class CacheControllerTest : public oatpp::test::UnitTest {
    public:

        CacheControllerTest( ) : UnitTest( "TEST[CacheControllerTest]" ) {}
        void onRun( ) override;

    };
}

#endif // CacheControllerTest_hpp
