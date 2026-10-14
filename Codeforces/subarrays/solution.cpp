#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix[i] = (prefix[i - 1] + x) % k;
    }

    vector<ll> freq(k, 0);

    ll ans = 0;

    for (int i = k + 1; i <= n; i++) {

        freq[prefix[i - k - 1]]++;
        ans += freq[prefix[i]];
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