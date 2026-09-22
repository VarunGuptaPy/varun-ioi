#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll W;
    cin >> n >> W;

    vector<ll> weight(n);
    vector<int> value(n);

    int sumValue = 0;

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
        sumValue += value[i];
    }

    const ll INF = 4e18;

    vector<ll> dp(sumValue + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int v = sumValue; v >= value[i]; v--) {
            dp[v] = min(dp[v],
                        dp[v - value[i]] + weight[i]);
        }
    }

    int ans = 0;

    for (int v = 0; v <= sumValue; v++) {
        if (dp[v] <= W) {
            ans = v;
        }
    }

    cout << ans << '\n';
}