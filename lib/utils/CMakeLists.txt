add_library(utils src/MatrixGraph.cpp src/ListGraph.cpp src/ArcGraph.cpp src/SetGraph.cpp src/IGraph.cpp)

target_include_directories(utils PUBLIC include)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(utils ${GTEST_LIBRARIES} pthread)
