#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    long long first, second;
    cin >> first >> second;
    long long large = max(first,second);
    long long small = min(first,second);
    if ((first + second) % 3 == 0 && large <= small * 2){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    // cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}