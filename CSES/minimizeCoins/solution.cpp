#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
int goSolve(vector<int>& coins, int left,vector<int> &dp){
    if (left == 0){
        return 0;
    }
    if (left < 0){
        return -1;
    }
    if (dp[left] != -2){
        return dp[left];
    }
    int minCoin = INT_MAX;
    for (int i = 1; i<=coins.size();i++){
        int coin = coins[i-1];
        int solve = goSolve(coins,left-coin,dp);
        if (solve != -1){
            minCoin = min(minCoin,1 + solve);

        }
    }
    if (minCoin == INT_MAX){
        dp[left] = -1;
        return -1;
    }
    dp[left] = minCoin;
    return dp[left];
}
void solve() {
    int n,s;
    cin >> n >> s;
    vector<int> coins;
    vector<int> dp(s+1, -2);
    for (int i = 0; i<n;i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    cout << goSolve(coins,s,dp);
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