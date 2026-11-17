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
    ll zeroCount = count(s.begin(),s.end(),'0');
    ll oneCount = n - zeroCount;
    ll a = max(zeroCount,oneCount);
    ll b = min(zeroCount,oneCount);
    ll flips = min((ll)k,b);
    a += flips;
    b -= flips;
    cout << 1 + a*(a+1)/2 + b*(b+1)/2 << '\n';
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