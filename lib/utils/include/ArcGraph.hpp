#pragma once

#include "IGraph.hpp"
#include <iostream>
#include <vector>
#include <cassert>

class ArcGraph: public IGraph {

public:
    ArcGraph(int size_) : size(size_) {}

    ArcGraph(const IGraph &graph) : adjacencyArray(graph.VerticesCount()) {
        size = graph.VerticesCount();
        for (int from = 0; from < size; ++from) {
            for (int to: graph.GetNextVertices(from)) {
                adjacencyArray.emplace_back(from, to);
            }
        }
    }

    ~ArcGraph() {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override { return static_cast<int>(size); }

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> adjacencyArray;
    int size;
};
