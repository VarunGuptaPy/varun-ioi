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
    vector<ll> nArr(n+1);
    for (int i = 1; i<=n; i++){
        cin >> nArr[i];
    }
    vector<int> li(m+1);
    vector<int> ri(m+1);
    vector<int> di(m+1);
    for (int i = 1; i<=m; i++){
        cin >> li[i] >> ri[i] >> di[i];
    }
    vector<int> allOps(m+2,0);
    for (int i = 0; i<k; i++){
        int x,y;
        cin >> x >> y;
        allOps[x]+=1;
        allOps[y+1]-=1;
    }
    vector<ll> allNChanges(n+2,0);
    for (int i = 1; i<=m; i++){
        allOps[i] += allOps[i-1];
        int l = li[i];
        int r = ri[i];
        int d = di[i];
        allNChanges[l]+= 1LL * d*allOps[i];
        allNChanges[r+1] -= 1LL * d*allOps[i];
    }
    for (int i = 1; i<=n; i++){
        allNChanges[i] += allNChanges[i-1];
        cout << nArr[i] + allNChanges[i] << ' ';
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