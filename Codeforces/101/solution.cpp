#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> ones;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            ones.push_back(i);
    }

    int bestL = -1;
    int bestR = -1;
    int bestLen = 0;

    // No fixed 1 exists
    if (ones.empty()) {
        int firstMinus = -1;
        int lastMinus = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (firstMinus == -1)
                    firstMinus = i;

                lastMinus = i;
            }
        }

        // At least two -1s
        if (firstMinus != -1 && firstMinus != lastMinus) {
            bestL = firstMinus;
            bestR = lastMinus;
        }

        // Only one -1
        else if (firstMinus != -1) {
            bestL = firstMinus;
        }
    }

    // At least one fixed 1 exists
    else {

        // Try consecutive fixed 1s
        for (int i = 1; i < (int)ones.size(); i++) {
            int len = ones[i] - ones[i - 1] + 1;

            if (len > bestLen) {
                bestLen = len;
                bestL = ones[i - 1];
                bestR = ones[i];
            }
        }

        // Try putting 1 at earliest -1 before first fixed 1
        for (int i = 0; i < ones[0]; i++) {
            if (a[i] == -1) {
                int len = ones[0] - i + 1;

                if (len > bestLen) {
                    bestLen = len;
                    bestL = i;
                    bestR = ones[0];
                }

                break;
            }
        }

        // Try putting 1 at latest -1 after last fixed 1
        for (int i = n - 1; i > ones.back(); i--) {
            if (a[i] == -1) {
                int len = i - ones.back() + 1;

                if (len > bestLen) {
                    bestLen = len;
                    bestL = ones.back();
                    bestR = i;
                }

                break;
            }
        }
    }

    // Replace all remaining -1 with 0
    for (int &x : a) {
        if (x == -1)
            x = 0;
    }

    // Chosen endpoints become 1
    if (bestL != -1)
        a[bestL] = 1;

    if (bestR != -1)
        a[bestR] = 1;

    for (int x : a)
        cout << x << ' ';

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