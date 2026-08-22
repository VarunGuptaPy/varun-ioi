#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
int goSolve(int sum,int choice, int n,vector<vector<int>>& dp){
    if (sum == n){
        return 1;
    } 
    if (sum > n){
        return 0;
    }
    if (dp[sum][choice] != -1){
        return dp[sum][choice];
    }
    int total = 0;
    for (int i = 1; i <= 6; i++){
        total = (total + goSolve(sum+i,i,n,dp)) % 1000000007;
    }
    dp[sum][choice] = total ;
    return dp[sum][choice];
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n+1,vector<int>(7,-1));
    int ans = goSolve(0,0,n,dp);
    cout << ans;
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