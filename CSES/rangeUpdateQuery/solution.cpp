#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

struct FenwickTree {
    vector<ll> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }

    void update(int idx, ll delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
    ll query(int idx) {
        ll sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i<n;i++){
        cin >> arr[i];
    }
    FenwickTree ft(n);
    ft.update(1,arr[0]);
    for (int i = 1; i<n;i++){
        ft.update(i+1,arr[i]-arr[i-1]);
    }
    for (int i = 0; i<m;i++){
        int ins;
        cin >> ins;
        if (ins == 1){
            int l,r,u;
            cin >> l >> r >> u;
            ft.update(l,u);
            ft.update(r+1,-u);
        } else {
            int k;
            cin >> k;
            cout << ft.query(k) << '\n';
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