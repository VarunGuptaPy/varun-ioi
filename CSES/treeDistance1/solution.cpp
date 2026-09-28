#include <bits/stdc++.h>
using namespace std;

int maxn = 200005;
vector<int> dis(maxn, 0);

void dfs(vector<vector<int>>& nodes, int start, int parent) {
    for (int c : nodes[start]) {
        if (c != parent) {
            dis[c] = dis[start] + 1;
            dfs(nodes, c, start);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> nodes(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    // STEP 1: DFS from any node
    fill(dis.begin(), dis.end(), 0);
    dfs(nodes, 1, -1);

    // Find first endpoint of diameter
    int firstEnd = 1;

    for (int i = 1; i <= n; i++) {
        if (dis[i] > dis[firstEnd]) {
            firstEnd = i;
        }
    }

    // STEP 2: DFS from first endpoint
    fill(dis.begin(), dis.end(), 0);
    dfs(nodes, firstEnd, -1);

    vector<int> disfromFirst = dis;

    // Find second endpoint
    int secondEnd = firstEnd;

    for (int i = 1; i <= n; i++) {
        if (dis[i] > dis[secondEnd]) {
            secondEnd = i;
        }
    }

    // STEP 3: DFS from second endpoint
    fill(dis.begin(), dis.end(), 0);
    dfs(nodes, secondEnd, -1);

    vector<int> disfromSecond = dis;

    // STEP 4
    for (int i = 1; i <= n; i++) {
        cout << max(disfromFirst[i], disfromSecond[i]) << " ";
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}