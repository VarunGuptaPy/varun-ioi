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
    vector<int> array;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        array.push_back(num);
    }
    ll ans = 0;
    int start = 0;
    multiset<int> items;
    for(int end = 0; end < n; end++) {

    while(items.count(array[end])) {
        items.erase(items.find(array[start]));
        start++;
    }

    items.insert(array[end]);

    ans += end - start + 1;
}
    cout << ans;
}
// 1,2,3,4 
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