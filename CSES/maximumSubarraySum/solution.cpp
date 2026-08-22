#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

// int maxSum(int index, int sum, vector<int> &arr,vector<vector<int>> &dp){
//     if (index == arr.size()){
//         return sum;
//     }
//     if (dp[index][sum] != -1){
//         return dp[index][sum];
//     }
//     // including and going
//     int includingAndGoing = maxSum(index+1, sum+=arr[index],arr,dp);
//     // starting from current and going
//     int startingFromCurrent = maxSum(index+1, arr[index],arr,dp);
//     dp[index][sum] = max(includingAndGoing,startingFromCurrent);
//     return dp[index][sum];
// }
ll maxSum(vector<ll>& arr) {
    ll current = arr[0];
    ll ans = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        current = max(arr[i], current + arr[i]);
        ans = max(ans, current);
    }

    return ans;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr;
    for (int i = 0; i<n; i++){
        ll num;
        cin >> num;
        arr.push_back(num);
    }
    cout << maxSum(arr);
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