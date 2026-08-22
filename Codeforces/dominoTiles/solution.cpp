#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int solveIT(string &s, int index, int lastPair, int prev,
            vector<vector<vector<int>>> &dp) {

    if (index == s.size())
        return 1;

    int &ans = dp[index][lastPair + 1][prev + 1];

    if (ans != -1)
        return ans;

    ans = 0;

    for (char ch = '0'; ch <= '1'; ch++) {

        if (s[index] != '?' && s[index] != ch)
            continue;

        int curr = ch - '0';

        if (index == 0) {
            ans += solveIT(s, index + 1, -1, curr, dp);
        }
        else {
            int sum = prev + curr;

            if (lastPair == -1 || sum != lastPair) {
                ans += solveIT(s, index + 1, sum, curr, dp);
            }
        }
    }

    return ans;
}
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(4, vector<int>(3, -1))
    );

    int count = solveIT(s, 0, -1, -1, dp);

    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}