#include <vector>
#include <queue>

using namespace std;

int count_cc(bool edge[], int n) {
    // Check if the graph is directed
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (edge[i * n + j] != edge[j * n + i]) // If any non-symmetric edge is found, graph is directed
                return 0;
        }
    }

    // Function to perform breadth-first search (BFS)
    auto bfs = [&](int start, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v) {
                if (edge[u * n + v] && !visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    };

    // Count connected components using BFS
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bfs(i, visited);
            ++count;
        }
    }

    return count;
}

