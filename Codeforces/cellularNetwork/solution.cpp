#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> cities(n);
    vector<int> network(m);

    for (int &x : cities) cin >> x;
    for (int &x : network) cin >> x;

    int ans = 0;
    sort(cities.begin(), cities.end());
    sort(network.begin(), network.end());
    for (int city : cities) {
        auto it = lower_bound(network.begin(), network.end(), city);

        int mini = INT_MAX;

        // tower on right
        if (it != network.end())
            mini = min(mini, abs(city - *it));

        // tower on left
        if (it != network.begin()) {
            --it;
            mini = min(mini, abs(city - *it));
        }

        ans = max(ans, mini);
    }

    cout << ans;
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