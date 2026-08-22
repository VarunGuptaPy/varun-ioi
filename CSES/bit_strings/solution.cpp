#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n; i++){
        ans = (ans * 2)%1000000007;
    }
    cout << ans;
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