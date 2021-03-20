set(PROJECT_NAME xor-riddler)

set(SOURCES XorRiddler.cpp)

set(RIDDLER_SOURCES ${SOURCES} riddler.cpp)
set(SOLVER_SOURCES ${SOURCES} solver.cpp)
set(TEST_SOURCES ${SOURCES} TestXorRiddler.cpp)

add_executable(riddler ${RIDDLER_SOURCES})
add_executable(solver ${SOLVER_SOURCES})
add_executable(test-${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test-${PROJECT_NAME} GTest::GTest GTest::Main)

gtest_discover_tests(test-${PROJECT_NAME})