#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
int goSolve(vector<int>& coins,int s, int sum, vector<int>& dp){
    if (sum == s){
        return 1;
    }
    if (sum > s){
        return 0;
    }
    if (dp[sum] != -1){
        return dp[sum];
    }
    int count = 0;
    for (int i = 0; i<coins.size();i++){
        count = (count + goSolve(coins,s,sum+coins[i],dp)) % (1000000007);
    }
    dp[sum] = count;
    return dp[sum];
}
void solve() {
    int n,s;
    cin >> n >> s;
    vector<int> dp(s+1, -1);
    vector<int> coins;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        coins.push_back(num);
    }
    cout << goSolve(coins,s,0,dp);
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