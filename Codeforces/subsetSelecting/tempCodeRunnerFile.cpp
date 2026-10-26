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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    int mex = 0;
    int cnt = 0;
    for (int x : a) {
        if (x < mex) {
            cnt++;
        }
        else if (x == mex) {
            cnt++;
            if (cnt >= k) {
                mex++;
                cnt = 0;
            }
        }
        else {
            break;
        }
    }
    cout << mex << '\n';
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