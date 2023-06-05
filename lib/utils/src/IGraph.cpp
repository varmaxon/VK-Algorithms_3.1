#include "IGraph.hpp"

void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::string &result)
{
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        int currentVertex = qu.front();
        qu.pop();

        result += (std::to_string(currentVertex) + " ");

        for (int nextVertex: graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

void BFS(const IGraph &graph, std::string &result)
{
    result.clear();

    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            BFS(graph, i, visited, result);
    }
}

void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::string &result)
{
    visited[vertex] = true;

    result += (std::to_string(vertex) + " ");

    for (int nextVertex: graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
            DFS(graph, nextVertex, visited, result);
    }
}

void DFS(const IGraph &graph, std::string &result)
{
    result.clear();
    
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            DFS(graph, i, visited, result);
    }
}
