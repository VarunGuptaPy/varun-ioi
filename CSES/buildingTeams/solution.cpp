#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;

        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    vector<int> teams(n + 1, 0);

    for (int start = 1; start <= n; start++) {

        if (teams[start] != 0)
            continue;

        queue<int> items;

        teams[start] = 1;
        items.push(start);

        while (!items.empty()) {

            int item = items.front();
            items.pop();

            int changeTeam;

            if (teams[item] == 1)
                changeTeam = 2;
            else
                changeTeam = 1;

            for (int child : graph[item]) {

                // Child has no team yet
                if (teams[child] == 0) {
                    teams[child] = changeTeam;
                    items.push(child);
                }

                // Child already has SAME team
                else if (teams[child] == teams[item]) {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << teams[i] << " ";
    }
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