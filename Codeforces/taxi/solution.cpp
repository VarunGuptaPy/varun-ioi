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
    vector<int> groups(n);
    vector<int> counts(4);
    for (int i = 0;i<n;i++){
        cin >> groups[i];
        counts[groups[i]-1]++;
    }
    int ans = 0;
    ans += counts[3];
    ans+= counts[2];
    counts[0] = max(0,counts[0] - counts[2]);
    ans+= counts[1]/2;
    // one 2 left

    if (counts[1] % 2) {

        ans++;

        counts[0] = max(0, counts[0] - 2);

    }

    // remaining 1s, 4 per taxi

    ans += (counts[0] + 3) / 4;
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