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
    vector<int> s;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        s.push_back(num);
    }
    if (s.size() == 1){
        cout << 0 << '\n';
        return;
    }
    sort(s.begin(),s.end());
    int start = 0;
    int maxi = 1;
    int curr = 1;
    vector<int> ans;
    while (start < n-1){
        if (s[start+1] - s[start] <= k){
            curr++;
        } else {
            maxi = max(curr,maxi);
            curr = 1;
        }
        start++;
    }
    // if (curr != 0) curr++;a
    maxi = max(curr,maxi);
    cout << n - maxi << '\n';
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