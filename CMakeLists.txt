project(aac)
cmake_minimum_required(VERSION 3.10)

include_directories(include/)
link_directories(lib/)

if (UNIX)
    add_compile_options(-Wall -Wextra -Werror -O2 -std=c++17)
elseif(MSVC)
    add_compile_options(/Wall /std:c++17)    
endif()


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/SFML/lib/cmake/SFML)
if (SFML_OS_WINDOWS AND SFML_COMPILER_MSVC)
    find_package( SFML 2 COMPONENTS main audio graphics window system REQUIRED)
else()
    find_package( SFML 2 COMPONENTS audio graphics window system REQUIRED)
endif()

if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
else()
        set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
        message("\nSFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
        message("Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()

file(GLOB GEOMETRY_SRC src/Geometry/*.cpp)
file(GLOB GEOMETRY_HEADER include/Geometry/*.hpp)

file(GLOB CONVEX_HULL_SRC src/ConvexHull/convex_hull.cpp)
file(GLOB CONVEX_HULL_HEADER include/ConvexHull/*.hpp)

file(GLOB FAST_EXPO_SRC src/FastExponentiation/*.cpp)
file(GLOB FAST_EXPO_HEADER include/FastExponentiation/*.hpp)

file(GLOB BIG_REC_SRC src/BiggestRectangleInHistogram/*.cpp)
file(GLOB BIG_REC_HEADER include/BiggestRectangleInHistogram/*.hpp)

file(GLOB LIN_SYS_SRC src/LinearEquationSystem/*.cpp)
file(GLOB LIN_SYS_HEADER include/LinearEquationSystem/*.hpp)

add_executable( ${CMAKE_PROJECT_NAME}_ConvexHull
    src/ConvexHull/main.cpp
    ${CONVEX_HULL_SRC}
    ${CONVEX_HULL_HEADER}
    ${GEOMETRY_SRC}
    ${GEOMETRY_HEADER}
)

add_executable( ${CMAKE_PROJECT_NAME}_ConvexHullTest
    src/Test/convexHullTest.cpp
    src/Test/catch.cpp
    ${CONVEX_HULL_SRC}
    ${CONVEX_HULL_HEADER}
    ${GEOMETRY_SRC}
    ${GEOMETRY_HEADER}
)

add_executable( ${CMAKE_PROJECT_NAME}_BigRecTest
    src/Test/biggestRectangleInHistogramTest.cpp
    src/Test/catch.cpp
    ${BIG_REC_SRC}
    ${BIG_REC_HEADER}
)

add_executable( ${CMAKE_PROJECT_NAME}_FastExpoTest
    src/Test/fastExponentiationTest.cpp
    src/Test/catch.cpp
    ${FAST_EXPO_SRC}
    ${FAST_EXPO_HEADER}
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res/sansation.ttf
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res)

add_executable( ${CMAKE_PROJECT_NAME}_LinSysTest
    src/Test/linearEquationTest.cpp
    src/Test/catch.cpp
    ${LIN_SYS_SRC}
    ${LIN_SYS_HEADER}
)

target_link_libraries(${CMAKE_PROJECT_NAME}_ConvexHull sfml-graphics sfml-audio)
set_target_properties(${CMAKE_PROJECT_NAME}_ConvexHull PROPERTIES LINKER_LANGUAGE C)
