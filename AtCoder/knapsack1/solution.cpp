#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

ll goSolve(
    vector<ll>& vs,
    vector<ll>& ws,
    vector<vector<ll>>& dp,
    ll index,
    ll w
) {
    // No more items
    if (index == vs.size()) {
        return 0;
    }

    if (dp[index][w] != -1) {
        return dp[index][w];
    }

    // Option 1: Don't take current item
    ll notTake = goSolve(vs, ws, dp, index + 1, w);

    // Option 2: Take current item
    ll take = 0;

    if (ws[index] <= w) {
        take = vs[index] +
               goSolve(vs, ws, dp,
                       index + 1,
                       w - ws[index]);
    }

    return dp[index][w] = max(take, notTake);
}
void solve() {
    ll n, w;
    cin >> n >> w;

    vector<ll> vs(n);
    vector<ll> ws(n);

    for (int i = 0; i < n; i++) {
        cin >> ws[i] >> vs[i];
    }

    vector<vector<ll>> dp(
        n,
        vector<ll>(w + 1, -1)
    );

    cout << goSolve(vs, ws, dp, 0, w);
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