#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // dp[i][x] = number of valid arrays from 0...i
    // where the value at index i is x
    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));

    // Initialize first position
    if (arr[0] == 0) {
        for (int x = 1; x <= m; x++) {
            dp[0][x] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    // Fill remaining positions
    for (int i = 1; i < n; i++) {

        if (arr[i] == 0) {

            // Current position can be any value 1...m
            for (int x = 1; x <= m; x++) {

                dp[i][x] =
                    (dp[i - 1][x - 1]
                    + dp[i - 1][x]
                    + dp[i - 1][x + 1]) % MOD;
            }

        } else {

            // Current position must be arr[i]
            int x = arr[i];

            dp[i][x] =
                (dp[i - 1][x - 1]
                + dp[i - 1][x]
                + dp[i - 1][x + 1]) % MOD;
        }
    }

    // Last element may be 1...m
    ll ans = 0;

    for (int x = 1; x <= m; x++) {
        ans = (ans + dp[n - 1][x]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}