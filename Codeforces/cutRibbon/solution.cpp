#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int getRibbon(int n,int a,int b,int c,vector<int> &dp){
    if (n == 0){
        return 0;
    }
    if (n < 0){
        return INT_MIN;
    }
    if (dp[n] != -1){
        return dp[n];
    }
    int aCount = 1 + getRibbon(n-a,a,b,c,dp);
    int bCount = 1 + getRibbon(n-b,a,b,c,dp);
    int cCount = 1 + getRibbon(n-c,a,b,c,dp);
    dp[n] = max(aCount,max(bCount,cCount));
    return dp[n];
}

void solve() {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1, -1);
    int totalRibbon = getRibbon(n,a,b,c,dp);
    cout << totalRibbon;
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