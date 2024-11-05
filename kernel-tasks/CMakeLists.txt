set(PROJECT_NAME "string-reverse")

set(SOURCES string_reverse.c string_buffer.c)

set(TEST_SOURCES ${SOURCES}
    test_string_reverse.cpp
    test_string_buffer.cpp
)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock)

gtest_discover_tests(test-${PROJECT_NAME})