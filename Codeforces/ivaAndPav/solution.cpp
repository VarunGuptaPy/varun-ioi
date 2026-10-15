#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

vector<int> arr(200000, 0);
vector<vector<int>> segs(200000, vector<int>(31, 0));

int rangeAND(int l, int r) {
    int ans = 0;
    int len = r - l + 1;

    for (int j = 0; j < 31; j++) {
        int count = segs[r][j] -
                    (l > 0 ? segs[l-1][j] : 0);

        if (count == len) {
            ans |= (1 << j);
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int x = arr[i];

        for (int j = 0; j < 31; j++) {
            segs[i][j] = (i > 0 ? segs[i-1][j] : 0);

            if (x & (1 << j)) {
                segs[i][j]++;
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, k;
        cin >> l >> k;

        l--;

        // Even the first element doesn't satisfy the condition
        if (arr[l] < k) {
            cout << -1 << ' ';
            continue;
        }

        int low = l;
        int high = n - 1;
        int ans = l;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (rangeAND(l, mid) >= k) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        cout << ans + 1 << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}