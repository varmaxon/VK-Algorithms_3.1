#pragma once

#include <vector>
#include <cassert>
#include "IGraph.hpp"

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int size) {}

    MatrixGraph(const IGraph& graph): adjacencyMatrix(graph.VerticesCount()) {
        int size = graph.VerticesCount();
        for (int from = 0; from < size; ++from) {
            adjacencyMatrix[from].resize(size);
            auto neighbors = graph.GetNextVertices(from);
            for (const auto& to : neighbors) {
                adjacencyMatrix[from][to] = 1;
            }
        }
    }

    ~MatrixGraph() {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override { return static_cast<int>(adjacencyMatrix.size()); }

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<bool>> adjacencyMatrix;
};
