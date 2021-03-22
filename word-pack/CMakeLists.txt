set(PROJECT_NAME "word-packet")

set(SOURCES WordPack.cpp)

set(TEST_SOURCES ${SOURCES} TestWordPack.cpp)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} GTest::GTest GTest::Main)

gtest_discover_tests(test-${PROJECT_NAME})