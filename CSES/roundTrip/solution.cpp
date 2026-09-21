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

    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);

    int starts = -1;
    int ends = -1;

    // Need this because graph can be disconnected
    for (int source = 1; source <= n; source++) {

        if (visited[source])
            continue;

        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty() && starts == -1) {

            int node = q.front();
            q.pop();

            for (int next : graph[node]) {

                if (!visited[next]) {

                    visited[next] = true;
                    parent[next] = node;
                    q.push(next);

                } else if (parent[node] != next) {

                    // Found an edge connecting two
                    // already connected nodes
                    starts = node;
                    ends = next;

                    break;
                }
            }
        }

        if (starts != -1)
            break;
    }

    if (starts == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    /*
        Parent tree could look like:

                1
               / \
              2   3
              |   |
              4---5

        starts = 4
        ends   = 5

        parent chain of starts:
        4 -> 2 -> 1

        parent chain of ends:
        5 -> 3 -> 1

        We need to find their common ancestor.
    */

    vector<bool> ancestor(n + 1, false);

    int node = starts;

    while (node != -1) {
        ancestor[node] = true;
        node = parent[node];
    }

    // Find common ancestor
    int common = ends;

    while (!ancestor[common]) {
        common = parent[common];
    }

    // starts -> ... -> common
    vector<int> left;

    node = starts;

    while (node != common) {
        left.push_back(node);
        node = parent[node];
    }

    left.push_back(common);

    // ends -> ... -> common
    vector<int> right;

    node = ends;

    while (node != common) {
        right.push_back(node);
        node = parent[node];
    }

    /*
        left:
        4 2 1

        right:
        5 3

        We want:

        4 2 1 3 5 4

        so reverse right:
        3 5
    */

    reverse(right.begin(), right.end());

    vector<int> ans;

    for (int x : left)
        ans.push_back(x);

    for (int x : right)
        ans.push_back(x);

    // close cycle
    ans.push_back(starts);

    cout << ans.size() << '\n';

    for (int x : ans) {
        cout << x << " ";
    }

    cout << '\n';
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