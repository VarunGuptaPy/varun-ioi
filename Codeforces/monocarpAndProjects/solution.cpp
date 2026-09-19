#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    long long x, y, k;
    cin >> x >> y >> k;
    long long d = y - x;
    long long ans = 0;

    long long cnt = 0;

    // Only these terms need actual modulo calculation
    if (d >= x)
        cnt = min(k, d - x + 1);

    for (long long i = 0; i < cnt; i++) {
        ans += d % (x + i);
    }

    // For x+i > d, d % (x+i) = d
    ans += (k - cnt) * d;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}