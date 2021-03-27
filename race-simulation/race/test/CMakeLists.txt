set(TEST_SOURCES
    TestCompetitor.cpp
    TestRace.cpp
    TestRules.cpp
)

add_executable(test-${LIBRARY_NAME} ${TEST_SOURCES})

target_link_libraries(test-${LIBRARY_NAME}
    ${LIBRARY_NAME}
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
)

gtest_discover_tests(test-${LIBRARY_NAME})