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
    cout << "? 1 " << n << endl;
    int totalOnes;
    cin >> totalOnes;
    if (totalOnes == n || totalOnes == 0){
        cout << "! NO" << endl;
        return;
    }
    int start = totalOnes + 1;
    cout << "? " << start << " " << n << endl;
    int allZero;
    cin >> allZero;
    if (allZero == 0){
        cout << "! NO" << endl;
        return;
    }
    cout << "! YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}