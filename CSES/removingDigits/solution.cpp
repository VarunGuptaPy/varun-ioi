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
    ll steps = 0;
    while (n != 0){
        int copyN = n;
        int maxDigit = copyN % 10;
        copyN /= 10;
        while (copyN != 0){
            maxDigit = max(maxDigit,copyN%10);
            copyN /= 10;
        }
        n-=maxDigit;
        steps++;
    }
    cout << steps;
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