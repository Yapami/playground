set(PROJECT_NAME "race-simulation")

include_directories(mocks)

add_subdirectory(common)
add_subdirectory(race)
add_subdirectory(track)

add_executable(${PROJECT_NAME} main.cpp RaceSimulation.cpp)

target_link_libraries(${PROJECT_NAME} rs::race rs::track)