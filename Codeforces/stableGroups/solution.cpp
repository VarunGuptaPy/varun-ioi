#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> students;
    for (int i = 0; i<n; i++){
        ll num;
        cin >> num;
        students.push_back(num);
    }
    sort(students.begin(),students.end());
    vector<ll> costs;
    for (int i = 0; i<(n-1); i++){
        ll diff = (students[i+1]) - (students[i]);
        if (diff > x){
            ll totalToAdd = diff / x + (diff % x != 0) - 1;
            costs.push_back(totalToAdd);
        }
    }
    sort(costs.begin(),costs.end());
    ll groups = costs.size() + 1;
    for (ll cost: costs){
        if (cost<=k){
            k-=cost;
            groups--;
        } else {
            break;
        }
    }
    cout << groups;
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