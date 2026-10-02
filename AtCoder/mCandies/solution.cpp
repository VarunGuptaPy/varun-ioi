#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define MOD 1e9+7
ll goSolve(vector<int> &arr, int n, int currIndex,int kLeft,vector<vector<ll>> &dp){
    if (kLeft == 0 && currIndex != n){
        return 0;
    }
    if(currIndex == n && kLeft > 0 || kLeft < 0){
        return 0;
    }
    if(currIndex == n && kLeft == 0){
        return 1;
    }
    if(dp[currIndex][kLeft] != -1){
        return dp[currIndex][kLeft];
    }

    ll count = 0;
    
    for (int i = 1; i<=min(arr[currIndex],kLeft);i++){
        count += goSolve(arr,n,currIndex+1,kLeft - i, dp);
    }
    return dp[currIndex][kLeft] = count;
}
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i<n;i++){
        cin >> arr[i];
    }

    vector<vector<ll>> dp(n,vector<int>(k+1,-1));
    cout << goSolve(arr,n,0,k,dp);
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