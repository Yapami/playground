set(PROJECT_NAME "square-sums")

set(SOURCES SquareSums.cpp)

set(TEST_SOURCES ${SOURCES} TestSquareSums.cpp)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock)

gtest_discover_tests(test-${PROJECT_NAME})