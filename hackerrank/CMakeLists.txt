set(PROJECT_NAME hackerrank)

set(SOURCES
    # grading-students.cpp
    # apple-and-orange.cpp
    # number-line-jumps.cpp
    # between-two-sets.cpp
    # breaking-the-records.cpp
    # subarray-division.cpp
    # divisible-sum-pairs.cpp
    migratory-birds.cpp
)

set(TEST_SOURCES ${SOURCES})

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock pthread)

gtest_discover_tests(test-${PROJECT_NAME})