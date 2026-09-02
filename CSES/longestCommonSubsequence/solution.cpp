#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    for (int i = 0; i<m; i++){
        cin >> b[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i = n-1; i>= 0; i--){
        for (int j = m-1; j>= 0; j--){
            if (a[i] == b[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);;
            }
        }
    }
    int i = 0;
    int j = 0;
    vector<int> subSequence;
    while (i < n && j < m){
        if (a[i] == b[j]){
            subSequence.push_back(a[i]);
            i++;
            j++;
        } else if (dp[i+1][j] >= dp[i][j+1]){
            i++;
        } else {
            j++;
        }
    }
    cout << dp[0][0] << '\n';
    for (int num: subSequence){
        cout << num << ' ';
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