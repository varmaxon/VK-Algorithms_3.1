#include "MatrixGraph.hpp"

void MatrixGraph::AddEdge(int from, int to) {
    assert(to < adjacencyMatrix.size());
    assert(from < adjacencyMatrix.size());
    adjacencyMatrix[from][to] = 1;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> nextVertices;
    for (int to = 0; to < adjacencyMatrix.size(); to++) {
        if (adjacencyMatrix[vertex][to] == 1)
            nextVertices.push_back(to);
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencyMatrix.size(); from++) {
        if (adjacencyMatrix[from][vertex] == 1)
            prevVertices.push_back(from);
    }
    return prevVertices;
}
