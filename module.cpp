#include <vector>
using namespace std;

bool dfs(int node, vector<bool>& visited, vector<bool>& recStack, const vector<vector<int>>& adj) {
    if (!visited[node]) {
        visited[node] = true;
        recStack[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, recStack, adj)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                return true;
            }
        }
    }
    recStack[node] = false;
    return false;
}

bool hasCircularDependency(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        int a = edge[0];
        int b = edge[1];
        adj[a].push_back(b);
    }
    
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj)) {
                return true;
            }
        }
    }
    return false;
}