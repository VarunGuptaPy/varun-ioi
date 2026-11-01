
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int p, q;
    cin >> p >> q;

    string init, b;
    cin >> init >> b;

    vector<bool> used(p, false);
    
    for (int i = 0; i < q; i++) {
        bool found = false;

        for (int j = 0; j < p; j++) {
            if (init[j] == b[i] && !used[j]) {
                used[j] = true;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "NO\n";
            return;
        }
    }

    string a;
    for (int j = 0; j < p; j++) {
        if (!used[j]) {
            a.push_back(init[j]);
        }
    }

    sort(a.begin(), a.end());

    if (a == "isx") {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
