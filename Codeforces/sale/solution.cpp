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
    multiset<int> profitableTV;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        if (num < 0){
            profitableTV.insert(num);
        }
    }
    auto itr = profitableTV.begin();
    ll moneyEarned = 0;
    while (itr != profitableTV.end() && m != 0){
        moneyEarned += abs(*itr);
        m--;
        itr++;
    }
    cout << moneyEarned;
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