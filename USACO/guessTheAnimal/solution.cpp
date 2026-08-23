#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;

    cin >> n;

    vector<set<string>> animals(n);

    for (int i = 0; i < n; i++) {

        string name;

        int k;

        cin >> name >> k;

        for (int j = 0; j < k; j++) {

            string characteristic;

            cin >> characteristic;

            animals[i].insert(characteristic);

        }

    }

    int ans = 0;

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            int common = 0;

            for (const string &s : animals[i]) {

                if (animals[j].count(s)) {

                    common++;

                }

            }

            ans = max(ans, common + 1);

        }

    }

    cout << ans << '\n';

}

int main() {

    freopen("guess.in", "r", stdin);

    freopen("guess.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    solve();

}