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

    vector<int> nums(n);
    map<int, vector<int>> valIndMap;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        valIndMap[nums[i]].push_back(i);
    }

    // ansI[k] = minimum number whose maximum gap is exactly k
    vector<int> ansI(n + 1, INT_MAX);

    for (auto &[key, val] : valIndMap) {

        int maxDiff = 0;

        // Gap from beginning to first occurrence
        maxDiff = max(maxDiff, val[0] + 1);

        // Gaps between consecutive occurrences
        for (int i = 0; i + 1 < (int)val.size(); i++) {
            maxDiff = max(maxDiff, val[i + 1] - val[i]);
        }

        // Gap from last occurrence to end
        maxDiff = max(maxDiff, n - val.back());

        ansI[maxDiff] = min(ansI[maxDiff], key);
    }

    // If a number works for k, it also works for every k' > k.
    int ans = INT_MAX;

    for (int k = 1; k <= n; k++) {
        ans = min(ans, ansI[k]);

        if (ans == INT_MAX)
            cout << -1 << ' ';
        else
            cout << ans << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}