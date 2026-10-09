
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> sum;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        currSum += b[i];
        sum.push_back(currSum);
    }

    vector<int> ft(n + 1, 0);
    vector<int> pt(n + 1, 0);

    for (int i = 0; i < n; i++) {

        int prev = (i == 0 ? 0 : sum[i - 1]);

        int index = upper_bound(
            sum.begin() + i,
            sum.end(),
            a[i] + prev
        ) - sum.begin();

        ft[i] += 1;
        ft[index] -= 1;

        if (index < n) {
            int consumed = (index == i ? 0 : sum[index - 1] - prev);
            pt[index] += a[i] - consumed;
        }
    }

    int cSum = 0;

    for (int i = 0; i < n; i++) {
        cSum += ft[i];
        ft[i] = cSum;
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] * ft[i] + pt[i] << ' ';
    }

    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}
