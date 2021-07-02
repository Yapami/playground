set(PROJECT_NAME "parallel-min-max")

set(SOURCES ParallelMinMax.cpp)

set(TEST_SOURCES ${SOURCES} TestParallelMinMax.cpp)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock -ltbb)

gtest_discover_tests(test-${PROJECT_NAME})