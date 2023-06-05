#include "IGraph.hpp"
#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "ArcGraph.hpp"
#include "SetGraph.hpp"

#include "../src/tests.cpp"

#include <iostream>

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    // RunTests();

    // ListGraph listGraph(9);
    // listGraph.AddEdge(0, 1);
    // listGraph.AddEdge(0, 5);
    // listGraph.AddEdge(1, 2);
    // listGraph.AddEdge(1, 3);
    // listGraph.AddEdge(1, 5);
    // listGraph.AddEdge(1, 6);
    // listGraph.AddEdge(3, 2);
    // listGraph.AddEdge(3, 4);
    // listGraph.AddEdge(3, 6);
    // listGraph.AddEdge(5, 4);
    // listGraph.AddEdge(5, 6);
    // listGraph.AddEdge(6, 4);
    // listGraph.AddEdge(7, 8);

    // BFS(listGraph, [](int vertex){ std::cout << 1; });
    // DFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    // std::cout << std::endl;

    // Нужно продемонстрировать работу конструктора копирования, проинициализировав
    // графы разных классов друг от друга. Далее, показать, что вершины и ребра
    // успешно скопированы: число вершин осталось прежним, произвести BFS и DFS.

    // ArcGraph arcGraph(listGraph);
    // BFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    // DFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    // std::cout << std::endl;


    // MatrixGraph matrixGraph(arcGraph);
    // BFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    // DFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    // std::cout << std::endl;


    // SetGraph setGraph(matrixGraph);
    // BFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    // DFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    // std::cout << std::endl;

    return 0;
}
