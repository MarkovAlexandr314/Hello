cmake_minimum_required(VERSION 3.20)
project(exampleNode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra")

cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

include_directories(
    ${LIB_DIR}
)

# add_subdirectory(Fall_semester/graphics_classes/chessboard)


# add_subdirectory(Summer_Time/Arc)


# add_subdirectory(11/shape_primitives)
# add_subdirectory(sem23_project)
# add_subdirectory(LogicElements)
add_subdirectory(Fall_semester/Class_vector)
# add_subdirectory(a/Titanfall-3)
# add_subdirectory(Chess_n_b)
# add_subdirectory(Project/Titanfall-3)
# add_subdirectory(11/chessboard)
# add_subdirectory(11/my)
# add_subdirectory(11/my)
