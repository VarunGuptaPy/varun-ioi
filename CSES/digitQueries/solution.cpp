#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
static int cmp(pii a, pii b){
    return a.first < b.first;
}
static int cmp2(pii a, pii b){
    return a.second < b.second;
}
void solve() {
    int n;
    cin >> n;

    while (n--) {
        ll k;
        cin >> k;

        ll digit = 1;
        ll count = 9;
        ll start = 1;

        while (k > digit * count) {
            k -= digit * count;
            digit++;
            count *= 10;
            start *= 10;
        }

        ll num = start + (k - 1) / digit;
        int index = (k - 1) % digit;

        string s = to_string(num);
        cout << s[index] << '\n';
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