#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void goSolve(int x,int y,int m,int& maxi, int curr){
    if (curr > m){
        return ;
    }
    if (curr <= m){
        maxi = max(maxi,curr);
    }
    // choose x
    goSolve(x,y,m,maxi,curr+x);
    // choose y
    goSolve(x,y,m,maxi,curr+y);
}

void solve() {
    int x,y,m;
    cin >> x >> y >> m;
    int max = 0;
    goSolve(x,y,m,max,0);
    cout << max;
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