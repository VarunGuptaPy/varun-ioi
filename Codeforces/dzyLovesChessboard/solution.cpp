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
    vector<string> row;
    for (int i = 0; i<n; i++){
        string s;
        cin >> s;
        row.push_back(s);
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if(row[i][j] == '.'){
                if ((i+j)%2==0){
                    row[i][j] = 'B';
                } else {
                    row[i][j] = 'W';
                }
            }
        }
    }
    for (string s: row){
        cout << s << '\n';
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