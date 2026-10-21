#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)


void solve() {
    string s;
    cin >> s;
    int n = s.length()-1;
    int ans = 1;
    bool increase = false;
    bool decrease = false;
    for (int i = 1; i<n;i++){
        if (s[i-1] == s[i] && s[i+1] == s[i]){
            increase = true;
        }
        if (s[i-1] != s[i] && s[i+1] != s[i]){
            decrease = true;
        }
    }
    cout << ans + increase + decrease << '\n';
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