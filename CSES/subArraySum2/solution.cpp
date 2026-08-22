#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    int reqSum;
    vector<int> input;
    cin >> n >> reqSum;
    for (int i = 0; i<n;i++){
        int num;
        cin >> num;
        input.push_back(num);
    }
    map<ll,int> sumCount = {{0,1}};
    ll currSum = 0;
    ll ans = 0;
    for (int i = 0; i<n;i++){
        currSum += input[i];
        ans += sumCount[currSum - reqSum];
        sumCount[currSum]++;
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