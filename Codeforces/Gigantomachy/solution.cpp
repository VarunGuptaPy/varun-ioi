#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m;
    cin >> n >> m;
    vector<ll> giant1;
    for (int i = 0; i<n; i++){
        ll num;
        cin >> num;
        giant1.push_back(num);
    }
    vector<ll> giant2;
    for (int i = 0; i<m; i++){
        ll num;
        cin >> num;
        giant2.push_back(num);
    }
    ll giant1Survive = 0;
    for (int i = 0; i< n; i++){
        if (i != n-1){
            giant1Survive += giant1[i] - giant1[i+1] + 1;
        } else {
            giant1Survive += giant1[i];
        }
    }
    ll giant2Survive = 0;
    for (int i = 0; i<m; i++){
        if (i != m-1){
            giant2Survive += giant2[i] - giant2[i+1] + 1;
        } else {
            giant2Survive += giant2[i];
        }
    }
    if (giant2Survive > giant1Survive){
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
    }
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