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
    vector<int> nums;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int x = (1 << 30) - 1;
    for (int i = 0; i<n; i++){
        if (nums[i] != i){
            x &= nums[i];
        }
    }

    cout << x << '\n';
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