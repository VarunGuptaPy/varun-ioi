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

    long long bankBalance = 1;
    long long total = 0;

    for (int i = 1; i <= n; i++) {
        bankBalance *= 2;

        // First k-1 withdrawals as early as possible
        if (i < k) {
            total += bankBalance;
            bankBalance = 1;
        }
    }

    // kth withdrawal on the final day
    total += bankBalance;

    cout << total << '\n';
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