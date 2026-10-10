#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int x,y;
    cin >> x >> y;
    if (abs(x-y) > 1){
        cout << "-1\n";
        return;
    } else if (x == y){
        cout << x << '\n';
    }  else if (x > y){
        cout << x+1 << '\n';
    } else {
        cout << y << '\n';
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