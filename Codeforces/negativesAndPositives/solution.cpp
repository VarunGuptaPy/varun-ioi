#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
ll getMaxSum(vector<int>& arr,vector<vector<ll>> &dp, int n,int currIndex,bool flipped){
    if(currIndex == n){
        return 0;
    }
    if (dp[currIndex][flipped] != -1){
        return dp[currIndex][flipped];
    }
    ll sumWithoutChange = arr[currIndex] + getMaxSum(arr,dp,n,currIndex+1,0);
    ll sumWithChange = INT_MIN;
    if (currIndex != n-1){
        arr[currIndex+1] = -(arr[currIndex+1]);
        sumWithChange = -(arr[currIndex]) + getMaxSum(arr,dp,n,currIndex+1,1);
        arr[currIndex+1] = -(arr[currIndex+1]);
    }
    dp[currIndex][flipped] = max(sumWithoutChange, sumWithChange);
    return dp[currIndex][flipped];
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(2,-1));
    cout << getMaxSum(arr,dp,n,0,0) << '\n';
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