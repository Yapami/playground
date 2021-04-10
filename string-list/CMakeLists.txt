set(PROJECT_NAME "string-list")

set(SOURCES main.cpp)

set(TEST_SOURCES ${SOURCES})

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} GTest::gtest_main GTest::gmock)

gtest_discover_tests(test-${PROJECT_NAME})