#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int &x : nums) {
        cin >> x;
    }

    if (n == 1) {
        cout << nums[0] << '\n';
        return;
    }

    cout << gcd(nums[0], nums[n - 1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}