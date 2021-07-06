set(PROJECT_NAME "codewars")

set(SOURCES
    camel-case.cpp
    digital-root.cpp
    duplicate-encoder.cpp
    square-sum.cpp
    directions-reduction.cpp
    find-outliner.cpp
)

set(TEST_SOURCES ${SOURCES})

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock)

gtest_discover_tests(test-${PROJECT_NAME})