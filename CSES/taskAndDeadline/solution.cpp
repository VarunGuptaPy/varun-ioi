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
    vector<pii> pairs;
    for (int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        pairs.push_back({a,b});
    }
    sort(pairs.begin(),pairs.end());
    ll totalTime = 0;
    ll ans = 0;
    for (int i = 0; i<n; i++){
        totalTime += pairs[i].first;
        ans += pairs[i].second - totalTime;
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