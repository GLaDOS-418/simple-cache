cmake_minimum_required(VERSION 3.1)

set(project_name kv_store)

project(${project_name})

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


add_library(${project_name}-lib
        "src/cache/ICache.h"
        "src/cache/LRUCache.h"
        "src/cache/LRUCache.cpp"
        "src/controller/CacheProxy.h"
        "src/controller/CacheController.h"
        
        "src/dto/AddEntryDto.h"
        "src/dto/RetrieveEntryDto.h"
        )

## link libs
target_include_directories(${project_name}-lib PUBLIC src)

## add executables
add_executable(${project_name}-exe
        "src/server/App.cpp"
        "src/server/AppComponent.h"
       # "src/server/SwaggerComponent.h"
        )

## link lib with exe
target_link_libraries(${project_name}-exe ${project_name}-lib)

add_dependencies(${project_name}-exe ${project_name}-lib)

## test exe
add_executable(${project_name}-test
        "test/app/CacheApiTestClient.h"
        "test/app/TestComponent.hpp"
        "test/CacheControllerTest.h"
        "test/CacheControllerTest.cpp"
        "test/tests.cpp"
  )

target_link_libraries(${project_name}-test ${project_name}-lib)


## add conan libs to both exe and test
target_link_libraries(${project_name}-exe ${CONAN_LIBS})
target_link_libraries(${project_name}-test ${CONAN_LIBS})

add_dependencies(${project_name}-test ${project_name}-lib)

set_target_properties(${project_name}-lib ${project_name}-exe ${project_name}-test PROPERTIES
        CXX_STANDARD 17
)

 ## enable_testing()
 ## add_test(project-tests ${project_name}-test)
