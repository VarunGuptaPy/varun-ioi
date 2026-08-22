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
    string stones;
    cin >> stones;
    int i = 0;
    int steps = 0;
    while (i < (n-1)){
        if (stones[i] == stones[i+1]){
            stones.erase(i,1);
            n-= 1;
            steps++;
        } else {
            i++;
        }
    }
    cout << steps << "\n";
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