#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)


void solve() {
    int n;
    cin >> n;
    vector<string> grid;
    for (int i = 0; i<n; i++){
        string row;
        cin >> row;
        grid.push_back(row);
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, LLONG_MAX));

    dp[n][n-1] = 0;
    for (int i = n-1; i>=0; i--){
        for (int j = n-1; j>=0; j--){
            char character = grid[i][j];
            int charInt = character - 'A'+1;
            dp[i][j] = charInt + min(dp[i+1][j],dp[i][j+1]);
        }
    }
    int i = 0;
    int j = 0;
    string path = "";
    while (i < n && j < n){
        path.push_back(grid[i][j]);
        if (dp[i+1][j] <= dp[i][j+1]){
            i++;
        } else {
            j++;
        }
    }
    cout << path;
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