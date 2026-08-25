#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> players(m+1);
    for (int i = 0; i<=m; i++){
        cin >> players[i];
    }
    int fedor = players[m];
    int freinds = 0;
    for (int i = 0; i<m; i++){
        int diff = fedor^players[i];
        int count = 0;
        while(diff != 0){
            if(diff&1) count++;
            diff = diff >> 1;
        }
        if (count <= k){
            freinds++;
        }
    }
    cout << freinds;
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