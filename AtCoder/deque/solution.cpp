#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[3001][3001];

ll getMaxScore(vector<int>& arr, int start, int end) {
    if (start > end) {
        return 0;
    }

    if (dp[start][end] != LLONG_MIN) {
        return dp[start][end];
    }

    ll firstRemoval = arr[start]
                    - getMaxScore(arr, start + 1, end);

    ll secondRemoval = arr[end]
                     - getMaxScore(arr, start, end - 1);

    return dp[start][end] = max(firstRemoval, secondRemoval);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    fill(&dp[0][0], &dp[0][0] + 3001 * 3001, LLONG_MIN);

    cout << getMaxScore(arr, 0, n - 1) << '\n';
}