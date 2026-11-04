#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,k;
    cin >> n >> k;
    vector<pii> movies;
    for (int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        movies.push_back({b,a});
    }
    sort(movies.begin(),movies.end());
    multiset<int> available;
    for (int i = 0; i<k; i++){
        available.insert(0);
    }
    int ans = 0;
    for (auto [end,start]: movies){
        auto it = available.upper_bound(start);
        if (it == available.begin()){
            continue;
        }
        it--;
        available.erase(it);
        available.insert(end);
        ans++;
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