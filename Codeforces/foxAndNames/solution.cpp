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
    vector<string> names(n);
    for (int i = 0; i<n; i++){
        cin >> names[i];
    }
    map<char,vector<char>> updations;
    for (int i = 0; i < n; i++) {

        string currString = names[i];

        for (int j = i + 1; j < n; j++) {

            string nowString = names[j];

            bool changed = false;

            for (int k = 0; k < min(currString.size(), nowString.size()); k++) {

                if (currString[k] != nowString[k]) {

                    updations[currString[k]].push_back(nowString[k]);

                    changed = true;

                    break;

                }

            }

            if (currString.size() > nowString.size() && changed == false) {

                cout << "Impossible\n";

                return;

            }

        }

    }
    map<char, int> indegree;

    for (char c = 'a'; c <= 'z'; c++) {

        indegree[c] = 0;

    }


    for (auto [u, neighbours] : updations) {

        for (char v : neighbours) {

            indegree[v]++;

        }

    }

    queue<char> q;

    for (char c = 'a'; c <= 'z'; c++) {

        if (indegree[c] == 0) {

            q.push(c);

        }

    }

    string output = "";

    while (!q.empty()) {

        char curr = q.front();

        q.pop();

        output += curr;

        for (char next : updations[curr]) {

            indegree[next]--;

            if (indegree[next] == 0) {

                q.push(next);

            }

        }

    }

    if (output.size() != 26) {

        cout << "Impossible\n";

    } else {

        cout << output << "\n";

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