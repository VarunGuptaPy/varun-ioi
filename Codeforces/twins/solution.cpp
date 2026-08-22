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
    ll sum = 0;;
    vector<int> coins;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        sum += num;
        coins.push_back(num);
    }
    sort(coins.begin(),coins.end());
    ll choosenSum = 0;
    int countCoins = 0;
    int start = n-1;
    while(sum >= choosenSum && start >= 0){
        choosenSum += coins[start];
        sum -= coins[start];
        countCoins++;
        start--;
    }
    cout << countCoins;
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