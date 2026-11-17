
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> diff(n - 1);

    ll ans = 0;
    int maxIndex = 0;

    for (int i = 0; i < n - 1; i++) {
        diff[i] = abs(a[i] - a[i + 1]);

        if (diff[i] > ans) {
            ans = diff[i];
            maxIndex = i;
        }
    }

    vector<ll> pref(n, 0), suff(n, 0);

    for (int i = 1; i < n; i++) {
        pref[i] = max(pref[i - 1], diff[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--) {
        suff[i] = max(suff[i + 1], diff[i]);
    }

    auto check = [&](int l, int r, ll insideMax) {
        ll curr = 2 * insideMax;

        if (l > 0) {
            curr = max(curr, pref[l - 1]);
            curr = max(curr, abs(a[l - 1] - 2 * a[r]));
        }

        if (r + 1 < n) {
            curr = max(curr, suff[r + 1]);
            curr = max(curr, abs(2 * a[l] - a[r + 1]));
        }

        ans = min(ans, curr);
    };

    int l = maxIndex + 1;
    ll insideMax = 0;

    for (int r = l; r < n; r++) {
        if (r > l) {
            insideMax = max(insideMax, diff[r - 1]);
        }

        check(l, r, insideMax);
    }
    int r = maxIndex;
    insideMax = 0;

    for (int l = r; l >= 0; l--) {
        if (l < r) {
            insideMax = max(insideMax, diff[l]);
        }

        check(l, r, insideMax);
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
}
