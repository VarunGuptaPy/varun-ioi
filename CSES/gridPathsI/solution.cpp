#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int editX[2] = {1,0};
int editY[2] = {0,1};
int pathCount(vector<string> &rows, int row,int x,int y,vector<vector<int>> &dp){
    if (x == row || x < 0 || y == row || y < 0 || rows[y][x] == '*'){
        return 0 ;
    }
    if (x == row-1 && y == row-1){
        return 1;
    }
    if (dp[y][x] != -1){
        return dp[y][x];
    }
    int count = 0;
    for (int i = 0; i<2; i++){
        count = (count+  pathCount(rows,row,x+editX[i],y+editY[i],dp)) % 1000000007;
    }
    dp[y][x] = count;
    return dp[y][x];
}
void solve() {
    int row;
    cin >> row;
    vector<string> rows;
    for (int i = 0; i< row; i++){
        string currRow;
        cin >> currRow;
        rows.push_back(currRow);
    }
    vector<vector<int>> dp(row+1,vector<int>(row+1,-1));
    int count = pathCount(rows,row,0,0,dp);
    cout << count;
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