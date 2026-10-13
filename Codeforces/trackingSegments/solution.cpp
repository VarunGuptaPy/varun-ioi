#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pii = pair<int, int>;

using vi = vector<int>;

#define all(x) begin(x), end(x)

#define rall(x) rbegin(x), rend(x)

class SegmentTree {

private:

    vector<ll> tree;

    int n;

    void build(vector<int>& arr, int idx, int l, int r) {

        if (l == r) {

            tree[idx] = arr[l];

            return;

        }

        int mid = l + (r - l) / 2;

        build(arr, 2 * idx + 1, l, mid);

        build(arr, 2 * idx + 2, mid + 1, r);

        tree[idx] =

            tree[2 * idx + 1] +

            tree[2 * idx + 2];

    }

    void update(int idx, int l, int r, int pos, int val) {

        if (l == r) {

            tree[idx] = val;

            return;

        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {

            update(2 * idx + 1, l, mid, pos, val);

        } else {

            update(2 * idx + 2, mid + 1, r, pos, val);

        }

        tree[idx] =

            tree[2 * idx + 1] +

            tree[2 * idx + 2];

    }

    ll query(int idx, int l, int r, int ql, int qr) {

        // No overlap

        if (r < ql || l > qr) {

            return 0;

        }

        // Complete overlap

        if (ql <= l && r <= qr) {

            return tree[idx];

        }

        // Partial overlap

        int mid = l + (r - l) / 2;

        return query(2 * idx + 1, l, mid, ql, qr)

             + query(2 * idx + 2, mid + 1, r, ql, qr);

    }

public:

    SegmentTree(vector<int>& arr) {

        n = arr.size();

        tree.resize(4 * n);

        build(arr, 0, 0, n - 1);

    }

    void update(int pos, int val) {

        update(0, 0, n - 1, pos, val);

    }

    ll query(int l, int r) {

        return query(0, 0, n - 1, l, r);

    }

};

// Global for valid()

int n;

vector<pii> segs;

vector<int> queries;

// Check whether after first k queries

// at least one segment becomes beautiful

bool valid(int k) {

    vector<int> arr(n, 0);

    // Apply first k operations

    for (int i = 0; i < k; i++) {

        arr[queries[i]] = 1;

    }

    // Build segment tree on current array

    SegmentTree tree(arr);

    // Check all segments

    for (auto seg : segs) {

        int l = seg.first;

        int r = seg.second;

        ll ones = tree.query(l, r);

        int length = r - l + 1;

        // Strictly more 1s than 0s

        if (2 * ones > length) {

            return true;

        }

    }

    return false;

}

void solve() {

    int m;

    cin >> n >> m;

    segs.resize(m);

    // Read segments

    for (int i = 0; i < m; i++) {

        cin >> segs[i].first >> segs[i].second;

        // Convert to 0-based

        segs[i].first--;

        segs[i].second--;

    }

    int q;

    cin >> q;

    queries.resize(q);

    // Read operations

    for (int i = 0; i < q; i++) {

        cin >> queries[i];

        // Convert to 0-based

        queries[i]--;

    }

    // Binary search earliest number of operations

    // which makes a segment beautiful

    int l = 1;

    int r = q;

    int ans = -1;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (valid(mid)) {

            ans = mid;

            // It works.

            // Try fewer operations.

            r = mid - 1;

        } else {

            // Not enough operations.

            l = mid + 1;

        }

    }

    cout << ans << '\n';

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