cmake_minimum_required(VERSION 3.1)

set(project_name kv_store) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


add_library(${project_name}-lib
        "src/server/AppComponent.hpp"
        "src/controller/CacheController.cpp"
        "src/controller/CacheController.hpp"
        "src/dto/AddEntryDto.h"
 "src/dto/RetrieveEntryDto.h")

## link libs

target_include_directories(${project_name}-lib PUBLIC src)

## add executables

add_executable(${project_name}-exe
        "src/server/App.cpp"
        #test/app/MyApiTestClient.hpp
        #"src/dto/RetrieveEntryDto.h"
        )

target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

#add_executable(${project_name}-test
#        test/tests.cpp
#        test/app/TestComponent.hpp
#        test/app/MyApiTestClient.hpp
#        test/MyControllerTest.cpp
#        test/MyControllerTest.hpp
# )

#target_link_libraries(${project_name}-test ${project_name}-lib)
target_link_libraries(${project_name}-exe ${CONAN_LIBS})

#add_dependencies(${project_name}-test ${project_name}-lib)

#set_target_properties(${project_name}-lib ${project_name}-exe ${project_name}-test PROPERTIES
#        CXX_STANDARD 11
#        CXX_EXTENSIONS OFF
#        CXX_STANDARD_REQUIRED ON
#)

# enable_testing()
# add_test(project-tests ${project_name}-test)
