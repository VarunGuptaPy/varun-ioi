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
    string s;
    cin >> s;
    set<int> indexOne;
    for (int i = 0; i<n; i++){
        if (s[i] == '1'){
            indexOne.insert(i);
        }
    }
    int ans = 0;
    for (int i = 0; i<n;i++){
        if (s[i] == '0') {
            auto it = indexOne.lower_bound(i);

            bool rightOkay = (it == indexOne.end() || *it - i > k);

            bool leftOkay = true;
            if (it != indexOne.begin()) {
                auto left = prev(it);
                leftOkay = (i - *left > k);
            }

            if (leftOkay && rightOkay) {
                ans++;
                indexOne.insert(i);
            }
        }
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