#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    ll n;
    cin >> n;
    vector<ll> sticks;
    for (ll i = 0; i<n; i++){
        ll num; cin >> num; sticks.push_back(num);
    }
    sort(sticks.begin(),sticks.end());
    ll median = sticks[n/2];
    ll ans = 0;
    for (ll i =0; i<n; i++){
        ans += abs(sticks[i] - median);
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