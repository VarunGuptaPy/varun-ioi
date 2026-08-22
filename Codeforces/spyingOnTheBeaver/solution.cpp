#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
    }

    int m;
    cin >> m;

    vector<int> dam(m);

    for (int &x : dam) {
        cin >> x;
    }

    // Minimum possible number of cameras
    cout << m - 1;

    // Because p[i] < i, the smallest numbered dam
    // cannot have another dam as its ancestor.
    int skip = *min_element(dam.begin(), dam.end());

    for (int x : dam) {
        if (x != skip) {
            cout << " " << x;
        }
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}