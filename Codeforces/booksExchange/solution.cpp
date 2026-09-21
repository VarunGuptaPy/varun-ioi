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

    vector<int> changes(n);

    for (int i = 0; i < n; i++) {
        cin >> changes[i];
    }

    vector<int> ans(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {

        if (visited[i])
            continue;

        vector<int> cycle;

        int current = i;

        while (!visited[current]) {

            visited[current] = true;
            cycle.push_back(current);

            current = changes[current] - 1;
        }

        int cycleLength = cycle.size();

        for (int node : cycle) {
            ans[node] = cycleLength;
        }
    }

    for (int x : ans) {
        cout << x << " ";
    }

    cout << '\n';
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