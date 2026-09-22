#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int getLongest(vector<vector<int>>& graph, vector<int>& dp, int curr) {
    if (dp[curr] != -1) {
        return dp[curr];
    }

    int longest = 0;

    for (int child : graph[curr]) {
        longest = max(longest, 1 + getLongest(graph, dp, child));
    }

    return dp[curr] = longest;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> dp(n + 1, -1);

    int longest = 0;

    for (int i = 1; i <= n; i++) {
        longest = max(longest, getLongest(graph, dp, i));
    }

    cout << longest << '\n';
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