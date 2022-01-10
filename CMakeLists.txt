project(aac)
cmake_minimum_required(VERSION 3.10)

include_directories(include/)
link_directories(lib/)

if (UNIX)
    add_compile_options(-Wall -Wextra -Werror -O2 -std=c++17)
endif()

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

file(GLOB CONVEX_HULL_SRC src/ConvexHull/*.cpp)
file(GLOB CONVEX_HULL_HEADER include/ConvexHull/*.hpp)

file(GLOB FAST_EXPO_SRC src/FastExponentiation/*.cpp)
file(GLOB FAST_EXPO_HEADER include/FastExponentiation/*.hpp)

add_executable( ${CMAKE_PROJECT_NAME}_ConvexHull
    ${CONVEX_HULL_SRC}
    ${CONVEX_HULL_HEADER}
    ${GEOMETRY_SRC}
    ${GEOMETRY_HEADER}
)

add_executable( ${CMAKE_PROJECT_NAME}_FastExpo
    ${FAST_EXPO_SRC}
    ${FAST_EXPO_HEADER}
)

target_link_libraries(${CMAKE_PROJECT_NAME}_ConvexHull sfml-graphics sfml-audio)
set_target_properties(${CMAKE_PROJECT_NAME}_ConvexHull PROPERTIES LINKER_LANGUAGE C)
