#include <iostream>
#include <vector>
#include <cassert>
struct Edge {
    int vertex;
    Edge *next;
};

bool is_directed(Edge **edges, int vertices) {
    std::vector<std::vector<bool>> reciprocal(vertices, std::vector<bool>(vertices, false));
    
    // Mark all existing edges as reciprocal initially
    for (int i = 0; i < vertices; ++i) {
        for (Edge *e = edges[i]; e != nullptr; e = e->next) {
            reciprocal[i][e->vertex] = true;
        }
    }

    // Check for each edge if its reciprocal exists
    for (int i = 0; i < vertices; ++i) {
        for (Edge *e = edges[i]; e != nullptr; e = e->next) {
            if (!reciprocal[e->vertex][i]) {
                // If reciprocal edge is not found, graph is directed
                return true;
            }
        }
    }

    // If all edges have reciprocals, graph is undirected
    return false;
}


// Helper function to perform DFS
void DFS(int v, std::vector<bool> &visited, Edge **edges) {
    visited[v] = true;
    for (Edge *e = edges[v]; e != nullptr; e = e->next) {
        if (!visited[e->vertex]) {
            DFS(e->vertex, visited, edges);
        }
    }
}

// Function to count the number of connected components
int count_cc(Edge **edges, int vertices) {
    if (is_directed(edges, vertices)) {
        return 0; // Return 0 if the graph is directed
    }

    // Initialize all vertices as unvisited
    std::vector<bool> visited(vertices, false);
    int count = 0;

    // Perform DFS for each unvisited vertex
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            DFS(i, visited, edges);
            ++count;
        }
    }

    return count;
}





