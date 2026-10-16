#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) : n(size) {
        tree.resize(4 * n);
    }

    void update(int idx, int val) {
        updateUtil(0, 0, n - 1, idx, val);
    }

private:
    void updateUtil(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] += val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateUtil(2 * node + 1, start, mid, idx, val);
            } else {
                updateUtil(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
};

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0;i<n;i++){
        cin >> arr[i];
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