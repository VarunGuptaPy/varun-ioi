
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    int oddA = 0, oddB = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x % 2 != 0) oddA++;
    }

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x % 2 != 0) oddB++;
    }

    if (k % 2 == 0) {
        cout << (oddB <= oddA ? "YES" : "NO") << '\n';
    } else {
        cout << (oddB >= oddA ? "YES" : "NO") << '\n';
    }
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
