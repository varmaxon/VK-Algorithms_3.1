#include "SetGraph.hpp"

void SetGraph::AddEdge(int from, int to) {
    assert(from < adjacencySets.size());
    assert(to < adjacencySets.size());
    adjacencySets[from].insert(to);
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex < adjacencySets.size());
    std::vector<int> nextVertices;
    for (const auto& to : adjacencySets[vertex]) {
        nextVertices.push_back(to);
    }
    return nextVertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex < adjacencySets.size());
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencySets.size(); ++from) {
        if (adjacencySets[from].find(vertex) != adjacencySets[from].end()) {
            prevVertices.push_back(from);
            break;
        }
    }
    return prevVertices;
}
