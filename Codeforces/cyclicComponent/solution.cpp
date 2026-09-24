#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph,
         vector<bool>& visited,
         int current,
         bool& isCycle) {

    visited[current] = true;

    // For a component to be a simple cycle,
    // every vertex must have exactly 2 edges.
    if (graph[current].size() != 2) {
        isCycle = false;
    }

    for (int child : graph[current]) {
        if (!visited[child]) {
            dfs(graph, visited, child, isCycle);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {

            bool isCycle = true;

            dfs(graph, visited, i, isCycle);

            if (isCycle) {
                count++;
            }
        }
    }

    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}