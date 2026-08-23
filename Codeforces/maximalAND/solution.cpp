#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,k;
    cin >> n >> k;
    int arr[32] = {0};
    int maxIndex = 0;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        int index = 0;
        while(num != 0){
            if(num&1){
                arr[index]++;
                maxIndex = max(maxIndex,index);
            }
            index++;
            num >>= 1;
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {

        int cost = n - arr[i];

        if (cost <= k) {

            ans |= (1 << i);

            k -= cost;

        }

    }
    cout << ans << "\n";
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