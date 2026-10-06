#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct As {
    int w;
    int s;
    ll v;
};

vector<As> values;
vector<vector<ll>> dp;

int n;
int maxWeight;

ll go(int id, int wOnTop) {
    if (id == n) {
        return 0;
    }

    if (dp[id][wOnTop] != -1) {
        return dp[id][wOnTop];
    }

    // Don't take this block
    ll ans = go(id + 1, wOnTop);

    // Put this block below the existing tower
    if (wOnTop <= values[id].s) {
        ans = max(
            ans,
            values[id].v +
            go(id + 1, wOnTop + values[id].w)
        );
    }

    return dp[id][wOnTop] = ans;
}

void solve() {
    cin >> n;

    values.resize(n);

    maxWeight = 0;

    for (int i = 0; i < n; i++) {
        cin >> values[i].w
            >> values[i].s
            >> values[i].v;

        maxWeight = max(
            maxWeight,
            values[i].w + values[i].s
        );
    }

    sort(values.begin(), values.end(),
        [](const As& left, const As& right) {
            return left.w + left.s
                 < right.w + right.s;
        }
    );

    dp.assign(
        n,
        vector<ll>(maxWeight + 1, -1)
    );

    cout << go(0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}