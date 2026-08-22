#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;

    vector<int> lamps(n);

    for (int i = 0; i < n; i++) {
        cin >> lamps[i];
    }

    sort(lamps.begin(), lamps.end());

    double maxDistance = 0;

    for (int i = 1; i < n; i++) {
        maxDistance = max(
            maxDistance,
            static_cast<double>(lamps[i] - lamps[i - 1])
        );
    }

    double leftDistance = lamps[0];
    double rightDistance = l - lamps[n - 1];

    double ans = max({
        maxDistance / 2.0,
        leftDistance,
        rightDistance
    });

    cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}