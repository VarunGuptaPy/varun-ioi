#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> built;

    for (int i = 0; i < n; i++){
        string row = "";
        for (int j = 0; j < m; j++){
            char ch;
            cin >> ch; 
            for (int curr = 'A'; curr<='D'; curr++){
                if (ch == curr){
                    continue;
                }
                if (i != 0 && built[i-1][j] == curr){
                    continue;
                }
                if (j != 0 && row[j-1] == curr){
                    continue;
                }
                row.push_back(curr);
                break;
            }

        }
        cout << row << '\n';
        built.push_back(row);
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