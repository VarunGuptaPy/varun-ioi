#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
void solve(){
    int n,k,q;
    cin >> n >> k >> q;
    int consecutive = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {

        int temp;

        cin >> temp;

        if (temp <= q) {

            consecutive++;

            if (consecutive >= k) {

                ans += consecutive - k + 1;

            }

        } else {

            consecutive = 0;

        }

    }

    cout << ans << '\n';
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