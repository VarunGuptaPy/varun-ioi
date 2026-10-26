#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
vector<int> vals;
bool check(int mid, int x, int n) {
    int extra = 0;

    for (int i = 0; i < n; i++) {
        bool left = (i > 0 && vals[i] - vals[i - 1] <= mid);
        bool right = (i + 1 < n && vals[i + 1] - vals[i] <= mid);
        if (left || right) {
            continue;
        } 
        if (i + 1 < n && vals[i + 1] - vals[i] <= 2LL * mid) {
            extra++;
            i++;
        } else {
            extra++;
        }
    }

    return extra <= x;
}
void solve() {
    int n;
    int x;
    vals = {};
    cin >> n >> x;
    vals.resize(n);
    for (int i = 0; i<n; i++){
        cin >> vals[i];
    }
    int low = 1;
    int high = 1e9;
    while (low < high){
        int mid = low + (high - low)/2;
        if (check(mid,x,n)){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << '\n';
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