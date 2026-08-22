#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    vector<int> u;
    vector<ll> vSum;
    vector<ll> uSum;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    u = v;
    sort(u.begin(),u.end());
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = 0; i < n; i++){
        sum1 += v[i];
        sum2 += u[i];
        vSum.push_back(sum1);
        uSum.push_back(sum2);
    }
    int m;
    cin >> m;
    for (int i = 0; i<m; i++){
        int type,l,r;
        cin >> type >> l >> r;
        if (type == 1){
            ll sum = vSum[r-1] - vSum[l-1] + v[l-1];
            cout << sum << '\n';
        } else {
            ll sum = uSum[r-1] - uSum[l-1] + u[l-1];
            cout << sum << '\n';
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