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
    vector<int> ins(n);
    vector<bool> completed(n,false);
    for (int i = 0; i<n; i++){
        cin >> ins[i];
    }
    map<int, vector<int>> possible;

for (int i = 0; i + 4 < n; i++) {
    int love = ins[i] + ins[i + 2] - ins[i + 4];
    possible[love].push_back(i);
}

long long ans = 0;

for (auto &[love, positions] : possible) {

    long long m = positions.size();

    // All pairs with equal love
    ans += m * (m - 1) / 2;

    unordered_set<int> exists(positions.begin(), positions.end());

    // Remove overlapping pairs
    for (int x : positions) {
        if (exists.count(x + 2))
            ans--;

        if (exists.count(x + 4))
            ans--;
    }
}

cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}