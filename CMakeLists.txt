project(aac)
cmake_minimum_required(VERSION 3.10)

include_directories(include/)
link_directories(lib/)

option(DEBUG "Enable debugging" OFF)

add_compile_options(-Wall -Wextra -Werror -O2 -std=c++17)

set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED system window graphics network audio)

file(GLOB CONVEX_HULL_SRC src/ConvexHull/*.cpp)
file(GLOB CONVEX_HULL_HEADER include/ConvexHull*.cpp)

add_executable( ${CMAKE_PROJECT_NAME}_ConvexHull
    ${CONVEX_HULL_SRC}
    ${CONVEX_HULL_HEADER}
)

target_link_libraries(${CMAKE_PROJECT_NAME}_ConvexHull sfml-graphics sfml-audio)
set_target_properties(${CMAKE_PROJECT_NAME}_ConvexHull PROPERTIES LINKER_LANGUAGE C)
