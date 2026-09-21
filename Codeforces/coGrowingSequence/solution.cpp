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
    vector<int> nums(n);
    for (int i = 0; i<n; i++){
        cin >> nums[i];
    }
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i<n; i++){
        if ((nums[i] & nums[i-1]) == nums[i-1]){
            ans.push_back(0);
        } else {
            int xora = nums[i]^nums[i-1];
            int count = 0;
            int copynum1 = nums[i-1];
            int copynum2 = nums[i];
            int xorVal = 0;
            while (copynum1 != 0 || copynum2 != 0){
                if (((copynum1 & 1) != 0) && ((copynum2 & 1) == 0)) {
                    xorVal += pow(2,count);
                }
                count++;
                copynum1 >>= 1;
                copynum2 >>=1;
            }
            nums[i] ^= xorVal;
            ans.push_back(xorVal);
        }
    }
    for (int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
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