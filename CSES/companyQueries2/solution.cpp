#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void dfs(vector<vector<int>> &nums,vector<vector<int>> &dp,int curr,int par){
    if (nums[curr].size() == 1 && nums[curr][0] == par){
        dp[curr][curr] = 0;
    }
    for (int child : nums[curr]){
        if (child != par){
            dfs(nums,dp,child,curr);

        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n+1);
    for (int i = 2; i<=n; i++){
        int par;
        cin >> par;
        nums[i].push_back(par);
        nums[par].push_back(i);
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    
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