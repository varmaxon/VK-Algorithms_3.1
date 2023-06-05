#pragma once

#include "IGraph.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <set>

class SetGraph: public IGraph {

public:
    SetGraph(int size) : adjacencySets(size) {}

    SetGraph(const IGraph &graph) : adjacencySets(graph.VerticesCount()) {
        for (int from = 0; from < adjacencySets.size(); ++from) {
            for (int to: graph.GetNextVertices(from)) {
                adjacencySets[from].insert(to);
            }
        }
    }

    ~SetGraph() {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override { return static_cast<int>(adjacencySets.size()); }

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<size_t>> adjacencySets;
};

