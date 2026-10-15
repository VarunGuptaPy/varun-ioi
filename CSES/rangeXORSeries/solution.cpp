#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    int curXOR = 0;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        curXOR ^= num;
        arr[i] = curXOR;
    }
    for (int i = 0; i<q; i++){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        int ans = arr[r] ^ (l == 0 ? 0 : arr[l-1]);
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