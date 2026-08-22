#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int T,A,B;
    int usedWater = 1;
    cin >> T >> A >> B;
    int fullness = 0;
    // int maxFull = 0;
    int bigger = max(A,B);
    while (fullness < T){
        if (fullness + A <= T && fullness + B <= T){
            fullness = fullness + bigger;
        } else if (fullness + A <= T){
            fullness = fullness + A;
        } else if (fullness + B <= T){
            fullness = fullness + B;
        } else if (usedWater != 0){
            fullness = fullness/2;
            usedWater = 0;
        } else {
            break;
        }
    }
    cout << fullness;
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