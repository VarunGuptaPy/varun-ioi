#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
int goSolve(vector<vector<int>> &activityHappiness,vector<vector<int>> &dp,int lastChoosen, int day,int maxDay){
    if (day == maxDay){
        return 0;
    }
    if (dp[day][lastChoosen] != -1){
        return dp[day][lastChoosen];
    }
    int maxSum = INT_MIN;
    for (int i = 1; i<4;i++){
        if (i != lastChoosen){
            maxSum = max(maxSum,activityHappiness[day][i-1]+goSolve(activityHappiness,dp,i,day+1,maxDay));
        }
    }
    dp[day][lastChoosen] = maxSum;
    return dp[day][lastChoosen];
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> activityHappiness;
    for (int i = 0; i<n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        activityHappiness.push_back({a,b,c});
    }
    vector<vector<int>> dp(n,vector<int>(4,-1));
    int ans = goSolve(activityHappiness,dp,0,0,n);
    cout << ans;
}

// void solve()
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