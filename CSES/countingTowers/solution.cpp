#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int totalHeights;
    cin >> totalHeights;
    vector<int> heights(totalHeights);
    int maxHeight = 0;
    for (int i = 0; i < totalHeights; i++) {
        cin >> heights[i];
        maxHeight = max(maxHeight, heights[i]);
    }
    int height = maxHeight;

    const long long MOD = 1e9 + 7;

    vector<vector<long long>> dp(height + 1, vector<long long>(2, 0));

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= height; i++) {
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
    }

    for (int i = 0; i < totalHeights; i++) {
        cout << (dp[heights[i]][0] + dp[heights[i]][1]) % MOD << '\n';
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