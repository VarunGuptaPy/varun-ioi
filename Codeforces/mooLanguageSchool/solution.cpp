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
    string binary;
    cin >> binary;
    int ans = 0;
    for (int i = 0; i<n; i+=k){
        bool containsZero = false;
        for (int j = i; j<i+k;j++){
            if (binary[j] == '0'){
                containsZero = true;
                break;
            }
        }
        if (!containsZero){
            ans++;
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