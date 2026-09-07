#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string s1, s2;

    cin >> s1 >> s2;

    int n = s1.size();

    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++) {

        dp[n][j] = m - j;

    }

    // s2 finished -> delete remaining s1 chars

    for (int i = 0; i <= n; i++) {

        dp[i][m] = n - i;

    }

    for (int i = n - 1; i >= 0; i--) {

        for (int j = m - 1; j >= 0; j--) {

            if (s1[i] == s2[j]) {

                dp[i][j] = dp[i + 1][j + 1];

            } else {

                int replace = dp[i + 1][j + 1];

                int del = dp[i + 1][j];

                int add = dp[i][j + 1];

                dp[i][j] = 1 + min({replace, del, add});

            }

        }

    }

    cout << dp[0][0] << '\n';
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