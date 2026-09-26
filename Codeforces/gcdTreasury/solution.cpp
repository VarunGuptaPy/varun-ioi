#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    ll n;
    ll x;
    cin >> n >> x;
    
    vector<ll> nums(n);
    ll evenSum = 0;
    ll oddSum = 0;
    for (int i = 0; i<n; i++){
        cin >> nums[i];
    }
    
    vector<ll> primes;
    ll temp = x;
    for (ll p = 2; p * p <= temp; p++) {
        if (temp % p == 0) {
            primes.push_back(p);
            while (temp % p == 0) {
                temp /= p;
            }
        }
    }
    if (temp > 1) {

        primes.push_back(temp);

    }
    ll ans = 0;
    for (ll p: primes){
        ll sum = 0;
        for (ll v: nums){
            if (v%p == 0){
                sum += v;
            }
        }
        ans = max(ans,sum);
    }
    cout << ans << '\n';
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