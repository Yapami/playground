set(PROJECT_NAME "hash-check")

set(SOURCES HashCheck.cpp)

set(TEST_SOURCES ${SOURCES} TestHashCheck.cpp)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} GTest::gtest GTest::gtest_main)

gtest_discover_tests(test-${PROJECT_NAME})
