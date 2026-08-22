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
    vector<int> input;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        input.push_back(num);
    }
    ll currSum = 0;
    map<ll,int> sumMap;
    map<ll,int> divisorMap;
    sumMap[0] = 1;
    ll ans = 0;
    for (int number : input){
        currSum += number;
        int remainder = currSum % n;
        if (remainder < 0){
            remainder += n;
        }
        ans += sumMap[remainder];
        sumMap[remainder] += 1;
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