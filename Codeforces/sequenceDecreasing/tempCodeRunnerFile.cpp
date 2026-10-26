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
    bool ansis = false;
    for (int i = 0; i<n; i++){
        int v;
        cin >> v;
        if (v <= n-1){
            ansis = true;
        }
    }
    if (ansis){
        cout << n << '\n';
    } else {
        cout << 0 << '\n';
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