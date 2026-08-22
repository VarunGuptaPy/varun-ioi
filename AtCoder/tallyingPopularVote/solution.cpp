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
    int abstained = 0;
    map<int,int> votes;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        if (num == 0){
            abstained++;
        } else {
            votes[num]++;
        }
    }
    int ans = 0;
    for (int i = 1; i<=n; i++){
        if (votes[i] > abstained){
            ans++;
        }
    }
    cout << ans;
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