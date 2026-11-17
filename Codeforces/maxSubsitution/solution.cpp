#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
ll MOD = 1e9+7;

ll modpow(ll a, int b) {
    ll ans = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> count;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        arr[i] = num;
        count[num]+=1;
    }
    sort(arr.begin(),arr.end());

    ll ans = 0;
    int power = 1;
    for (int i = n-1; i>=0; i--){
        if (count[arr[i]] > 1){
            break;
        }
        ans =  (ans + modpow((arr[i] - 1),power)) % MOD;
        power++;
    }
    cout << (ans + 1) % MOD << '\n';
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