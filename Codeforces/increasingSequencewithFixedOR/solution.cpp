#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    long long n;
    cin >> n;

    vector<long long> out;

    for (int i = 0; i < 63; i++) {
        if (n & (1LL << i)) {
            long long x = n & ~(1LL << i);

            if (x > 0)
                out.push_back(x);
        }
    }

    reverse(out.begin(), out.end());

    out.push_back(n);

    cout << out.size() << '\n';

    for (long long x : out)
        cout << x << " ";

    cout << '\n';
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