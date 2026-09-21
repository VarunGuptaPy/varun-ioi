#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

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

    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == n)
            break;

        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = node;
                q.push(next);
            }
        }
    }

    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;

    int curr = n;

    while (curr != -1) {
        path.push_back(curr);

        if (curr == 1)
            break;

        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for (int node : path) {
        cout << node << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}