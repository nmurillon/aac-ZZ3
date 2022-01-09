project(aac)
cmake_minimum_required(VERSION 3.10)

include_directories(include/)
link_directories(lib/)

option(DEBUG "Enable debugging" OFF)

add_compile_options(-Wall -Wextra -Werror -O2 -std=c++17)

set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED system window graphics network audio)

file(GLOB CONVEX_HULL_SRC src/ConvexHull/*.cpp)
file(GLOB CONVEX_HULL_HEADER include/ConvexHull/*.hpp)

file(GLOB FAST_EXPO_SRC src/FastExponentiation/*.cpp)
file(GLOB FAST_EXPO_HEADER include/FastExponentiation/*.hpp)

file(GLOB BIG_REC_SRC src/BiggestRectangleInHistogram/*.cpp)
file(GLOB BIG_REC_HEADER include/BiggestRectangleInHistogram/*.hpp)

file(GLOB LIN_SYS_SRC src/LinearEquationSystem/*.cpp)
file(GLOB LIN_SYS_HEADER include/LinearEquationSystem/*.hpp)

add_executable( ${CMAKE_PROJECT_NAME}_ConvexHull
    ${CONVEX_HULL_SRC}
    ${CONVEX_HULL_HEADER}
)

add_executable( ${CMAKE_PROJECT_NAME}_FastExpo
    ${FAST_EXPO_SRC}
    ${FAST_EXPO_HEADER}
)

add_executable( ${CMAKE_PROJECT_NAME}_BigRec
    ${BIG_REC_SRC}
    ${BIG_REC_HEADER}
)

add_executable( ${CMAKE_PROJECT_NAME}_LinSys
    ${LIN_SYS_SRC}
    ${LIN_SYS_HEADER}
)

target_link_libraries(${CMAKE_PROJECT_NAME}_ConvexHull sfml-graphics sfml-audio)
set_target_properties(${CMAKE_PROJECT_NAME}_ConvexHull PROPERTIES LINKER_LANGUAGE C)
