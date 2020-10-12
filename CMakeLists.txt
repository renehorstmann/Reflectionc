cmake_minimum_required(VERSION 3.0)
project(reflectionc)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -march=native)  # march=native for best performance
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -Wno-unused-function -Wno-missing-braces")


add_library(reflectionc SHARED
        src/log.c
        src/types.c
        src/parse.c
        src/parsefile.c
        src/types.c
        src/filter.c
        )

target_include_directories(reflectionc PUBLIC include)


#
# install:
#
install(TARGETS reflectionc
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )
install(DIRECTORY include/ DESTINATION include)

#
# Testing
#

# Enables ctest (after "make", test with "ctest" or "ctest -V")
enable_testing()

# Define the executable test
add_executable(main tests/main.c)
add_executable(prototype tests/prototype.c)
add_executable(testparse tests/test_parse.c)
add_executable(testfilter tests/test_filter.c)

# link to the library
target_link_libraries(main reflectionc)
target_link_libraries(prototype reflectionc)
target_link_libraries(testparse reflectionc)
target_link_libraries(testfilter reflectionc)


# add the executable as test
add_test(TestParse testparse)
add_test(TestFilter testfilter)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tests/data/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
