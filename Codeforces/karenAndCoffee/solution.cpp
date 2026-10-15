#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> arr(200000,0);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i<n;i++){
        int l,r;
        cin >> l >> r;
        arr[l-1]+=1;
        arr[r]-=1;
        maxi = max(r-1,maxi);
        mini = min(l-1,mini);
    }
    int sum = 0;
    for (int i = 0; i<=maxi; i++){
        sum+= arr[i];
        arr[i] = (sum >= k) ? 1 : 0;
    }
    for (int i = 1;i<= maxi;i++){
        arr[i] += arr[i-1];
    }

    for (int i = 0; i<q;i++){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        r = min(r, maxi);
        if (l > r) {

            cout << 0 << '\n';

            continue;

        }
        int ans = arr[r] - (l > 0 ? arr[l-1] : 0);

        cout << ans << '\n';

    }
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