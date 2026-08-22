#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

// void solve() {
//     int n;
//     int sumReq;
//     cin >> n >> sumReq;
//     vector<int> in;
//     for (int i = 0; i<n; i++){
//         int num;
//         cin >> num;
//         in.push_back(num);
//     }
//     if (n == 1 && in[0] == sumReq){
//         cout << 1;
//         return;
//     }
//     int startVal = in[0];
//     int endVal = in[1];
//     int start = 0;
//     int end = 1;
//     int currSum = in[0] + in[1];
//     int ans = 0;
//     while (start != n && end != n && start <= end){
//         if (currSum < sumReq){
//             currSum-=in[start];
//             start++;
//             startVal = in[start];
//             currSum += in[start];
//         } else if (currSum == sumReq){
//             ans++;
//             currSum-=in[start];
//             start++;
//             startVal = in[start];
//             currSum += in[start];
//         } else if (currSum > sumReq){
//             end++;
//             endVal = in[end];
//             currSum += endVal;
//         }
//     }
//     cout << ans;
// }
void solve(){
    int n;
    int sumReq;
    cin >> n >> sumReq;
    vector<int> in;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        in.push_back(num);
    }
    int sum = 0;
    int i = 0;
    int j = 0;
    int total = 0;

    while(j<n){
        sum+= in[j];
        while (sum > sumReq){
            sum-= in[i];
            i++;
        }
        if (sum == sumReq){
            total++;
        }
        j++;
    }
    cout << total;
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