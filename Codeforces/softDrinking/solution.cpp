#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int totalDrink = k * l;
    int totalLimes = c * d;
    int totalSalt = p;
    int totalDrinks = totalDrink / nl;
    int totalSaltedDrinks = totalSalt / np;
    int totalPossibleDrinks = min({totalDrinks, totalLimes, totalSaltedDrinks});
    int answer = totalPossibleDrinks / n;
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}