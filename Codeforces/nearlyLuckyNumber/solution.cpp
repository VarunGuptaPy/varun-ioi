#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    ll n;
    cin >> n;
    int luckyCount = 0;
    while (n != 0){
        int lastDigit = n%10;
        if (lastDigit == 4 || lastDigit == 7){
            luckyCount++;
        }
        n /= 10;
    }
    if (luckyCount == 4 || luckyCount == 7){
        cout << "YES";
    } else {
        cout << "NO";
    }
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