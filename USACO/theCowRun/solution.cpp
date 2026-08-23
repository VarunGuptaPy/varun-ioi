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
    set<int> paths;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        paths.insert(num);
    }
    int curr = 0;
    int ans = 0;
    int totalTime = 0;
    while (!paths.empty()) {
        auto it = paths.lower_bound(curr);

        // Everything is smaller than curr
        if (it == paths.end()) {
            auto left = prev(paths.end());
            ans += totalTime + abs(curr - *left);
            totalTime += abs(curr - *left);
            curr = *left;
            paths.erase(left);
        }

        // Everything is >= curr
        else if (it == paths.begin()) {
            ans += abs(curr - *it);
            curr = *it;
            paths.erase(it);
        }

        // We have candidates on both sides
        else {
            auto left = prev(it);

            if (abs(curr - *it) <= abs(curr - *left)) {
                ans += totalTime + abs(curr - *it);
                totalTime += abs(curr - *it);
                curr = *it;
                paths.erase(it);
            } else {
                ans += totalTime + abs(curr - *left);
                totalTime += abs(curr - *left);
                curr = *left;
                paths.erase(left);
            }
        }
    }
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