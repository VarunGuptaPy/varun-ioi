#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll roadLength(ll x, ll y) {
    if (x == y) return 2;
    return 1;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    /*
        Initial path:

        a[0] -> b[0]
             -> a[1] -> b[1]
             -> a[2] -> b[2]
             ...
             -> a[n-1] -> b[n-1]

        Edges are:

        a[i] <-> b[i]

        and

        a[i] <-> b[i-1]   for i >= 1
    */

    ll curr = 0;

    // Vertical edges a[i] - b[i]
    for (int i = 0; i < n; i++) {
        curr += roadLength(a[i], b[i]);
    }

    // Diagonal edges b[i-1] - a[i]
    for (int i = 1; i < n; i++) {
        curr += roadLength(a[i], b[i - 1]);
    }

    ll thegrilla = curr;

    /*
        Move turning point towards the left.

        Going from turning point i+1 to i:

        remove: a[i] -- b[i]
        add:    a[i] -- b[i+1]
    */

    for (int i = n - 2; i >= 0; i--) {

        curr -= roadLength(a[i], b[i]);

        curr += roadLength(a[i], b[i + 1]);

        thegrilla = max(thegrilla, curr);
    }

    cout << thegrilla << '\n';
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