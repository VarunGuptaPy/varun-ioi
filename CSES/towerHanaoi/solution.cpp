#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
void TOH(int n, string a, string b, string c, vector<string> &moves){
    if (n>0){
        TOH(n-1,a,c,b,moves);
        moves.push_back(a + " " + c);
        TOH(n-1,b,a,c,moves);
    }
}
void solve() {
    int disks;
    cin >> disks;
    vector<string> moves;
    TOH(disks,"1","2","3",moves);
    int n = moves.size();
    cout << n << endl;
    for (int i = 0; i < n; i++){
        cout << moves[i] << endl;
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