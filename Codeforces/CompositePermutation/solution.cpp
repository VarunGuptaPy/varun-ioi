#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)



void solve() {
    int n;
    cin >> n;

    if (n < 4) {
        cout << -1 << '\n';
        return;
    }

    cout << "4 2 3 1 ";

    for (int i = 5; i <= n; i++) {
        cout << i << ' ';
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