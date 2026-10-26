#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string s;
ll memo[20][11][2][2];

ll dfs(int pos, int prev, bool tight, bool started) {

    if (pos == s.size()) {
        return 1;
    }

    ll &ans = memo[pos][prev][tight][started];

    if (ans != -1) {
        return ans;
    }

    ans = 0;

    int limit = tight ? s[pos] - '0' : 9;

    for (int digit = 0; digit <= limit; digit++) {

        if (started && digit == prev) {
            continue;
        }

        bool newStarted = started || (digit != 0);
        bool newTight = tight && (digit == s[pos] - '0');

        int newPrev = newStarted ? digit : 10;

        ans += dfs(pos + 1, newPrev, newTight, newStarted);
    }

    return ans;
}

ll countValid(ll x) {

    if (x < 0) return 0;

    s = to_string(x);

    memset(memo, -1, sizeof(memo));

    return dfs(0, 10, true, false);
}

void solve() {

    ll a, b;
    cin >> a >> b;

    cout << countValid(b) - countValid(a - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}