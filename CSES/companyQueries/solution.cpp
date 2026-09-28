#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 30;

int up[MAXN][LOG];

void solve() {
    int n, q;
    cin >> n >> q;

    // Employee 1 has no boss
    for (int j = 0; j < LOG; j++) {
        up[1][j] = -1;
    }

    // Direct boss
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
    }

    // Build jump table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {

            int previousBoss = up[i][j - 1];

            if (previousBoss == -1) {
                up[i][j] = -1;
            } else {
                up[i][j] = up[previousBoss][j - 1];
            }
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int j = 0; j < LOG; j++) {

            if (k & (1 << j)) {
                x = up[x][j];

                if (x == -1)
                    break;
            }
        }

        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}