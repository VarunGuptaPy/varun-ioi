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
    vector<int> input(n);
    vector<int> v;
    for (int i = 0; i<n; i++){
        cin >> input[i];
        if (input[i] < i+1){
            v.push_back(i+1);
        }
    }
    ll ans = 0;
    for(auto i: v){
        ans += lower_bound(v.begin(),v.end(), input[i - 1]) - v.begin();
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