set(PROJECT_NAME "codewars")

set(SOURCES
    # camel-case.cpp
    # digital-root.cpp
    # duplicate-encoder.cpp
    # square-sum.cpp
    # directions-reduction.cpp
    # find-outliner.cpp
    # vasya-clerk.cpp
    # tortoise-racing.cpp
    # roman-numerals.cpp
    # get-nearest.cpp
    # counting-duplicates.cpp
    # consecutive-strings.cpp
    # count-smiley.cpp
    # trailing-zeroes.cpp
    # last-digit.cpp
    # beeramid.cpp
    # sum-of-intervals.cpp
    # sum-strings.cpp
    # remove-product.cpp
    # twice-linear.cpp
    # determinant.cpp
    # infix-to-postfix.cpp
    tcp-fsm.cpp
)

set(TEST_SOURCES ${SOURCES})

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock)

gtest_discover_tests(test-${PROJECT_NAME})