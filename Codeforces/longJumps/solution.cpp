#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int getAns(int currIndex,int n,vector<int> &a, vector<int> &dp){
    if(currIndex >= n){
        return 0;
    }
    if(dp[currIndex] != -1) return dp[currIndex];
    int currSum = a[currIndex] + getAns(currIndex+a[currIndex],n,a,dp);
    dp[currIndex] = currSum;
    return dp[currIndex];
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    int maxVal = INT_MIN;
    vector<int> dp(n,-1);
    for (int i = 0; i<n; i++){
        int ansCurr = getAns(i,n,a,dp);
        maxVal = max(ansCurr,maxVal);
    }
    cout << maxVal << '\n';
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