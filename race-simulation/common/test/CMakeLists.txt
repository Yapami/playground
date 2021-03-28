set(TEST_SOURCES
    TestRng.cpp
)

add_executable(test-${LIBRARY_NAME} ${TEST_SOURCES})

target_link_libraries(test-${LIBRARY_NAME}
    ${LIBRARY_NAME}
    gtest
    gtest_main
    gmock
    pthread
)

gtest_discover_tests(test-${LIBRARY_NAME})