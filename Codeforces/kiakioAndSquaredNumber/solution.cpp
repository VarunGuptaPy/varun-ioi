#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int nxt(int x) {
    int sum = 0;

    while (x > 0) {
        int digit = x % 10;
        sum += digit * digit;
        x /= 10;
    }

    return sum;
}

void solve() {
    int n;
    cin >> n;

    unordered_map<int, ll> count;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // More than enough to reach the eventual cycle
        for (int j = 0; j < 100; j++) {
            x = nxt(x);
        }

        count[x]++;
    }

    ll ans = 0;

    for (auto &[value, cnt] : count) {
        ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}