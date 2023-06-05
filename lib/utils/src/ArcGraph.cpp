#include "ArcGraph.hpp"

void ArcGraph::AddEdge(int from, int to) {
    assert(from < size);
    assert(to < size);
    adjacencyArray.emplace_back(from, to);
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex < size);
    std::vector<int> nextVertices;
    for (const auto& pair : adjacencyArray) {
        if (pair.first == vertex) {
            nextVertices.push_back(pair.second);
        }
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex < size);
    std::vector<int> prevVertices;
    for (const auto& pair : adjacencyArray) {
        if (pair.second == vertex) {
            prevVertices.push_back(pair.first);
        }
    }
    return prevVertices;
}
