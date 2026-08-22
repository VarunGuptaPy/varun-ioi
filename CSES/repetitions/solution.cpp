#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string input;
    cin >> input;
    char lastChar = input[0];
    int count = 1;
    int ans = 1;
    for (int i = 1; i<=input.size();i++){
        if (lastChar == input[i]){
            count++;
        } else {
            ans = max(ans,count);
            count = 1;
            lastChar = input[i];
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