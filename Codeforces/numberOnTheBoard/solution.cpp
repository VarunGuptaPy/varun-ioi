
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    cout << min(b - a, max(0LL, abs(a + b) - 1)) << '\n';
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
