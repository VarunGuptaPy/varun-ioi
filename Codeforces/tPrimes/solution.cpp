#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
void solve() {
    ll n;
    if (!(cin >> n)) return;
    vector<ll> a(n);
    ll maxi = 0;
    for (ll i = 0; i < n; i++){
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }

    ll limit = (ll)floor(sqrt((long double)maxi));
    if (limit < 1) limit = 1;
    vector<char> isPrime(limit + 1, true);
    if (limit >= 0) isPrime[0] = false;
    if (limit >= 1) isPrime[1] = false;
    for (ll i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= limit; j += i) isPrime[j] = false;
        }
    }

    for (ll i = 0; i < n; ++i) {
        ll x = a[i];
        if (x == 1) {
            cout << "NO\n";
            continue;
        }
        ll r = (ll)llround(sqrt((long double)x));
        if (r * r == x && r <= limit && isPrime[r]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll test_cases = 1;

    while (test_cases--) {
        solve();
    }

    return 0;
}