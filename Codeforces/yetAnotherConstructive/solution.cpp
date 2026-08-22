#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, k;
    long long m;
    cin >> n >> k >> m;

    if (k > m) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for (int i = 1; i <= n; i++) {
        long long previous = (i - 1) % k;
        long long current = i % k;

        long long value = (current - previous + m) % m;

        if (value == 0) {
            value = m;
        }

        cout << value << " ";
    }

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