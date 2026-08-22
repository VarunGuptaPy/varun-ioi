#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int q;
    cin >> q;

    while(q--) {
        ll num;
        cin >> num;

        ll start = 1;
        ll end = num;
        ll ans = 0;

        while(start <= end) {
            ll mid = start + (end - start) / 2;

            if(mid <= num / mid) {  // avoids overflow from mid*mid
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        cout << ans << '\n';
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