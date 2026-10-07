#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string command;
    cin >> command;

    stack<int> mem;
    vector<bool> printed(n + 1, false);

    for (int i = 0; i < n; i++) {
        int doc = i + 1;

        if (command[i] == '1') {
            // Scan document i+1 into memory
            mem.push(doc);
        }

        else if (command[i] == '2') {
            if (!mem.empty()) {
                // Print top document from memory
                printed[mem.top()] = true;
                mem.pop();
            } else {
                // Memory empty -> print current document
                printed[doc] = true;
            }
        }

        else { // command[i] == '3'
            // Quick print current document
            printed[doc] = true;
        }
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (!printed[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';

    for (int x : ans) {
        cout << x << ' ';
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
}