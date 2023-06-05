#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <functional>

struct IGraph {
    virtual ~IGraph() {}

    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::string &result);
void BFS(const IGraph &graph, std::string &result);

void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::string &result);
void DFS(const IGraph &graph, std::string &result);
