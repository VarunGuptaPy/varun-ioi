#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> freq(n + 1, 0);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        freq[l]++;

        if (r + 1 < n) {
            freq[r + 1]--;
        }
    }

    for (int i = 1; i < n; i++) {
        freq[i] += freq[i - 1];
    }

    sort(arr.begin(), arr.end());
    sort(freq.begin(), freq.begin() + n);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += arr[i] * freq[i];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}