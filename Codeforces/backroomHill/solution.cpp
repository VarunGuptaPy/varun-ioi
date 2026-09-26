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
    vector<int> arr(n);
    vector<int> atEven;
    vector<int> atOdd;
    int peak = INT_MIN;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
        peak = max(peak,arr[i]);
        if (i%2==0){
            atEven.push_back(arr[i]);
        } else {
            atOdd.push_back(arr[i]);
        }
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