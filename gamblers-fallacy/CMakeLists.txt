set(PROJECT_NAME "gamblers-fallacy")

set(SOURCES GamblersFallacy.cpp)

set(TEST_SOURCES ${SOURCES} TestGamblersFallacy.cpp)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} GTest::gtest GTest::gtest_main GTest::gmock)

gtest_discover_tests(test-${PROJECT_NAME})