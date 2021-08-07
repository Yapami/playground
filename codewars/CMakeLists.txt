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
    # tcp-fsm.cpp
    # skyscrapers.cpp
    # connect-four.cpp
    # snail-sort.cpp
    # burrows-wheeler-trasformation.cpp
    # last-digit-extended.cpp
    # divide-strings.cpp
    # naive-subarray.cpp
    # ice-maze-solver.cpp
    # coloured-triangles.cpp
    # lift.cpp
    # rgb-to-hex.cpp
    # path-finder.cpp
    # square-sums.cpp
    # code-war.cpp
    # divide-strings.cpp
    # square-sums.cpp
    # range-extraction.cpp
    # permutations.cpp
    # quadratic-builder.cpp
    # boggle-word-checker.cpp
    # path-finder-shortest.cpp
    # rectangle-rotation.cpp
    tuple-sum.cpp
)

set(TEST_SOURCES ${SOURCES})

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock)

gtest_discover_tests(test-${PROJECT_NAME})