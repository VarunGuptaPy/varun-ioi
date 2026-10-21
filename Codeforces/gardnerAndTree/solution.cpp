#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> tree(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    queue<int> leaf;

    for (int i = 1; i <= n; i++) {
        if (degree[i] <= 1) {
            leaf.push(i);
        }
    }

    int ans = n;

    for (int i = 0; i < k; i++) {
        queue<int> newLeaf;

        while (!leaf.empty()) {
            int top = leaf.front();
            leaf.pop();

            ans--;

            for (int next : tree[top]) {
                if (degree[next] <= 0) continue;
                degree[next]--;

                if (degree[next] == 1) {
                    newLeaf.push(next);
                }
            }
        }
        if (newLeaf.empty()) break;
        leaf = newLeaf;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }
}