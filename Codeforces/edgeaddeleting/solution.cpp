#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> branch(n + 1, -1);
    vector<int> distFrom1(n + 1, -1);

    queue<int> q;
    q.push(1);
    distFrom1[1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child : graph[node]) {
            if (distFrom1[child] != -1)
                continue;

            distFrom1[child] = distFrom1[node] + 1;

            if (node == 1)
                branch[child] = child;
            else
                branch[child] = branch[node];

            q.push(child);
        }
    }
    vector<int> distFromN(n + 1, -1);

    q.push(n);
    distFromN[n] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child : graph[node]) {
            if (distFromN[child] != -1)
                continue;

            distFromN[child] = distFromN[node] + 1;
            q.push(child);
        }
    }

    int ans = distFrom1[n];

    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;

        if (branch[v] == branch[n]) {
            ans = max(ans, distFromN[v] + 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}