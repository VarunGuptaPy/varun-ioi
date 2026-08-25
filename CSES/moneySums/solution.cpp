#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void getSums(int index, int n,int currSum,vector<int> &coins, set<int> &sums, vector<vector<bool>> &dp){
    if (index == n){
        if(currSum == 0){
            return;
        }
        sums.insert(currSum);
        return;
    }
    if (dp[index][currSum]){
        return;
    }
    dp[index][currSum] = true;
    //choose
    getSums(index+1,n,currSum+coins[index],coins,sums,dp);
    //not choose
    getSums(index+1,n,currSum,coins,sums,dp);
}

void solve() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i<n; i++){
        cin >> coins[i];
    }
    set<int> sums;
    int maxSum = accumulate(coins.begin(), coins.end(), 0);
    vector<vector<bool>> dp(n+1, vector<bool>(maxSum+1, false));
    getSums(0,n,0,coins,sums,dp);
    cout << sums.size()<<'\n';
    for (int sum: sums){
        cout << sum << ' ';
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