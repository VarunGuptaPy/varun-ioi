#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)


double ans = 0;

void getData(int node, int pathlength,
             double probability,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

    visited[node] = true;

    int children = 0;

    for (int child : graph[node]) {
        if (!visited[child]) {
            children++;
        }
    }

    if (children == 0) {
        ans += pathlength * probability;
        return;
    }

    for (int child : graph[node]) {
        if (!visited[child]) {
            getData(child, pathlength + 1,
                    probability / children, graph, visited);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for (int i = 1; i<n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(n+1);
    getData(1,0,1.0,graph,visited);
    cout << fixed << setprecision(15) << ans << '\n';
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