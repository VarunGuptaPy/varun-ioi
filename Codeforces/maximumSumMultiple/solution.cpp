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
    int currAnsSum = 0;
    int ans = 0;
    for (int i = 2; i<=n; i++){
        int k = n/i;
        int sum = i * (k * (k+1))/2;
        if (sum > currAnsSum){
            ans = i;
            currAnsSum = sum;
        }
    }
    cout << ans << '\n';
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