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
    vector<int> arr;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    ll count = 0;
    int start = 0;
    map<int,ll> numCount;

    for (int end = 0; end < n; end++){
        numCount[arr[end]]++;
        int passed = end-start;
        while (numCount.size() > k) {
            numCount[arr[start]]--;
            if (numCount[arr[start]] == 0) {
                numCount.erase(arr[start]);
            }
            start++;
        }
        count += end - start + 1;
    }
    cout << count;
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