set(PROJECT_NAME "reverse-sentence")

set(SOURCES ReverseSentence.cpp)

set(TEST_SOURCES ${SOURCES} TestReverseSentence.cpp)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} GTest::GTest GTest::Main)

gtest_discover_tests(test-${PROJECT_NAME})