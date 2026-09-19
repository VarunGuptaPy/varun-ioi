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
    vector<int> problems(n);
    int counts[2] = {0,0};
    for (int i = 0; i<n; i++){
        cin >> problems[i];
        counts[problems[i]]++;
    }
    if (counts[0] < 2 ){
        cout << -1 << '\n';return;
    }
    if (problems[0] == 0 && problems[n-1] == 0){
        cout << 0 << '\n';return;
    }
    int ans = 0;
    if (problems[0] == 1){
        ans++;
    }
    if (problems[n-1] == 1){
        ans++;
    }
    cout << ans << '\n';
    return;
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