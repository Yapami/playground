set(PROJECT_NAME "bulls-and-cows")

set(SOURCES BullsAndCows.cpp)

set(TEST_SOURCES ${SOURCES} TestBullsAndCows.cpp)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock)

gtest_discover_tests(test-${PROJECT_NAME})