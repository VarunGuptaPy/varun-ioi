#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll y, x;
    cin >> y >> x;

    ll ans;

    if (y > x) {
        if (y % 2 == 0) {
            ans = y * y - x + 1;
        } else {
            ans = (y - 1) * (y - 1) + x;
        }
    } else {
        if (x % 2 == 1) {
            ans = x * x - y + 1;
        } else {
            ans = (x - 1) * (x - 1) + y;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}