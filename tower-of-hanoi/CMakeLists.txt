set(PROJECT_NAME "tower-of-hanoi")

set(SOURCES TowerOfHanoi.cpp)

set(TEST_SOURCES ${SOURCES} TestTowerOfHanoi.cpp)

add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} gtest gtest_main gmock)

gtest_discover_tests(test-${PROJECT_NAME})