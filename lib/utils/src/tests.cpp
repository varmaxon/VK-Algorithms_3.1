#include "IGraph.hpp"
#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"
#include "ArcGraph.hpp"

#include <gtest/gtest.h>
#include <string>


TEST(Graph, test1) {    // 1 компонента связности
    
    ListGraph listGraph(7);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);

    ArcGraph arcGraph(listGraph);
    MatrixGraph matrixGraph(arcGraph);
    SetGraph setGraph(matrixGraph);

    std::string bfs1, bfs2, bfs3, bfs4;
    std::string dfs1, dfs2, dfs3, dfs4;

    
    BFS(listGraph, bfs1);
    BFS(arcGraph, bfs2);
    BFS(matrixGraph, bfs3);
    BFS(setGraph, bfs4);

    DFS(listGraph, dfs1);
    DFS(arcGraph, dfs2);
    DFS(matrixGraph, dfs3);
    DFS(setGraph, dfs4);

    ASSERT_STREQ(bfs1.c_str(), "0 1 5 2 3 6 4 ");
    ASSERT_STREQ(bfs2.c_str(), bfs1.c_str());
    ASSERT_STREQ(bfs3.c_str(), bfs2.c_str());
    ASSERT_STREQ(bfs4.c_str(), bfs3.c_str());

    ASSERT_STREQ(dfs1.c_str(), "0 1 2 3 4 6 5 ");
    ASSERT_STREQ(dfs2.c_str(), dfs1.c_str());
    ASSERT_STREQ(dfs3.c_str(), dfs2.c_str());
    ASSERT_STREQ(dfs4.c_str(), dfs3.c_str());

}

TEST(Graph, test2) {    // 2 компонента связности
    
    ListGraph listGraph(9);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);
    listGraph.AddEdge(7, 8);


    ArcGraph arcGraph(listGraph);
    MatrixGraph matrixGraph(arcGraph);
    SetGraph setGraph(matrixGraph);

    std::string bfs1, bfs2, bfs3, bfs4;
    std::string dfs1, dfs2, dfs3, dfs4;

    
    BFS(listGraph, bfs1);
    BFS(arcGraph, bfs2);
    BFS(matrixGraph, bfs3);
    BFS(setGraph, bfs4);

    DFS(listGraph, dfs1);
    DFS(arcGraph, dfs2);
    DFS(matrixGraph, dfs3);
    DFS(setGraph, dfs4);

    ASSERT_STREQ(bfs1.c_str(), "0 1 5 2 3 6 4 7 8 ");
    ASSERT_STREQ(bfs2.c_str(), bfs1.c_str());
    ASSERT_STREQ(bfs3.c_str(), bfs2.c_str());
    ASSERT_STREQ(bfs4.c_str(), bfs3.c_str());

    ASSERT_STREQ(dfs1.c_str(), "0 1 2 3 4 6 5 7 8 ");
    ASSERT_STREQ(dfs2.c_str(), dfs1.c_str());
    ASSERT_STREQ(dfs3.c_str(), dfs2.c_str());
    ASSERT_STREQ(dfs4.c_str(), dfs3.c_str());

}

TEST(Graph, test3) {    // прямая линия

    
    ListGraph listGraph(6);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(4, 5);

    ArcGraph arcGraph(listGraph);
    MatrixGraph matrixGraph(arcGraph);
    SetGraph setGraph(matrixGraph);

    std::string bfs1, bfs2, bfs3, bfs4;
    std::string dfs1, dfs2, dfs3, dfs4;

    
    BFS(listGraph, bfs1);
    BFS(arcGraph, bfs2);
    BFS(matrixGraph, bfs3);
    BFS(setGraph, bfs4);

    DFS(listGraph, dfs1);
    DFS(arcGraph, dfs2);
    DFS(matrixGraph, dfs3);
    DFS(setGraph, dfs4);

    ASSERT_STREQ(bfs1.c_str(), "0 1 2 3 4 5 ");
    ASSERT_STREQ(bfs2.c_str(), bfs1.c_str());
    ASSERT_STREQ(bfs3.c_str(), bfs2.c_str());
    ASSERT_STREQ(bfs4.c_str(), bfs3.c_str());

    ASSERT_STREQ(dfs1.c_str(), "0 1 2 3 4 5 ");
    ASSERT_STREQ(dfs2.c_str(), dfs1.c_str());
    ASSERT_STREQ(dfs3.c_str(), dfs2.c_str());
    ASSERT_STREQ(dfs4.c_str(), dfs3.c_str());

}

TEST(Graph, test4) {    // Эйлеров цикл 
    
    ListGraph listGraph(3);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 0);

    ArcGraph arcGraph(listGraph);
    MatrixGraph matrixGraph(arcGraph);
    SetGraph setGraph(matrixGraph);

    std::string bfs1, bfs2, bfs3, bfs4;
    std::string dfs1, dfs2, dfs3, dfs4;

    
    BFS(listGraph, bfs1);
    BFS(arcGraph, bfs2);
    BFS(matrixGraph, bfs3);
    BFS(setGraph, bfs4);

    DFS(listGraph, dfs1);
    DFS(arcGraph, dfs2);
    DFS(matrixGraph, dfs3);
    DFS(setGraph, dfs4);

    ASSERT_STREQ(bfs1.c_str(), "0 1 2 ");
    ASSERT_STREQ(bfs2.c_str(), bfs1.c_str());
    ASSERT_STREQ(bfs3.c_str(), bfs2.c_str());
    ASSERT_STREQ(bfs4.c_str(), bfs3.c_str());

    ASSERT_STREQ(dfs1.c_str(), "0 1 2 ");
    ASSERT_STREQ(dfs2.c_str(), dfs1.c_str());
    ASSERT_STREQ(dfs3.c_str(), dfs2.c_str());
    ASSERT_STREQ(dfs4.c_str(), dfs3.c_str());

}

TEST(Graph, test5) {    // все вершины связаны друг с другом
    
    ListGraph listGraph(4);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 0);
    listGraph.AddEdge(0, 2);
    listGraph.AddEdge(3, 1);


    ArcGraph arcGraph(listGraph);
    MatrixGraph matrixGraph(arcGraph);
    SetGraph setGraph(matrixGraph);

    std::string bfs1, bfs2, bfs3, bfs4;
    std::string dfs1, dfs2, dfs3, dfs4;

    
    BFS(listGraph, bfs1);
    BFS(arcGraph, bfs2);
    BFS(matrixGraph, bfs3);
    BFS(setGraph, bfs4);

    DFS(listGraph, dfs1);
    DFS(arcGraph, dfs2);
    DFS(matrixGraph, dfs3);
    DFS(setGraph, dfs4);

    ASSERT_STREQ(bfs1.c_str(), "0 1 2 3 ");
    ASSERT_STREQ(bfs2.c_str(), bfs1.c_str());
    ASSERT_STREQ(bfs3.c_str(), bfs2.c_str());
    ASSERT_STREQ(bfs4.c_str(), bfs3.c_str());

    ASSERT_STREQ(dfs1.c_str(), "0 1 2 3 ");
    ASSERT_STREQ(dfs2.c_str(), dfs1.c_str());
    ASSERT_STREQ(dfs3.c_str(), dfs2.c_str());
    ASSERT_STREQ(dfs4.c_str(), dfs3.c_str());

}
