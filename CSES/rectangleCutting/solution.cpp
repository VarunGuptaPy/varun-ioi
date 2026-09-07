#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int a,b;
    cin >> a >> b;
    int steps = 0;
    while (a != b){
        if (a > b){
            a -= b;
        } else if (a < b){
            b -= a;
        }
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