cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

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
add_subdirectory("topological-sort")