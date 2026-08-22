#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> nArray;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nArray.insert(num);
    }

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        auto it = nArray.upper_bound(num);

        if (it == nArray.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            nArray.erase(it);
        }
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