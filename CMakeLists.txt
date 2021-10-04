cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)

project(playground)

find_package(GTest REQUIRED)

include(GoogleTest)

enable_testing()

# add_subdirectory("cmake-template")
# add_subdirectory("xor-riddler")
# add_subdirectory("bulls-and-cows")
# add_subdirectory("word-pack")
# add_subdirectory("reverse-sentence")
# add_subdirectory("gamblers-fallacy")
# add_subdirectory("race-simulation")
# add_subdirectory("sharpers-hand")
# add_subdirectory("string-list")
# add_subdirectory("template-specialization")
# add_subdirectory("topological-sort")
# add_subdirectory("letter-puzzle")
# add_subdirectory("partition")
# add_subdirectory("set-operations")
# add_subdirectory("phone-number")
# add_subdirectory("square-sums")
# add_subdirectory("tower-of-hanoi")
# add_subdirectory("parallel-min-max")
# add_subdirectory("rectangle-rotation")
# add_subdirectory("codewars")
add_subdirectory(hackerrank)