#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int count(vector<int> &p, int val, int indexToReplace,int &zeroCount,vector<vector<vector<int>>> &dp,vector<vector<vector<int>>> &dpZero){
    if (p[indexToReplace] == 0){
        zeroCount--;
        return 1;
    }
    if(zeroCount == 0){
        return 0;
    }
    if(dp[val][indexToReplace][zeroCount] != -1){
        zeroCount = dpZero[val][indexToReplace][zeroCount];
        return dp[val][indexToReplace][zeroCount];
    }
    int originalZero =  zeroCount;
    int anotherVal = p[indexToReplace];
    dp[val][indexToReplace][originalZero] = 1 + count(p,anotherVal,anotherVal,zeroCount,dp,dpZero);
    dpZero[val][indexToReplace][originalZero] = zeroCount;
    return dp[val][indexToReplace][originalZero];

}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1,-1);
    vecotr<int> q(n+1,-1);
    for (int i = 1; i<=n; i++){
        cin >> p[i];
    }
    for (int i = 1; i<=n; i++){
        cin >> q[i];
    }
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
    vector<vector<vector<int>>> dpZero(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
    int zeroCount = 0;
    vector<int> pCopy = p;
    for (int query: q){
        zeroCount++;
        int copyZerocoun = zeroCount;
        int val = pCopy[query];
        pCopy[query] = 0;
        
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