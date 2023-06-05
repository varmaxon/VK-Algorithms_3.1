#pragma once

#include "IGraph.hpp"
#include <iostream>
#include <vector>
#include <cassert>

class ListGraph: public IGraph {

public:
    ListGraph(int size) : adjacencyLists(size) {}

    ListGraph(const IGraph &graph) : adjacencyLists(graph.VerticesCount()) {
        for (int i = 0; i < graph.VerticesCount(); i++) {
            adjacencyLists[i] = graph.GetNextVertices(i);
        }
    }

    ~ListGraph() {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override { return static_cast<int>(adjacencyLists.size()); }

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};
