#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
vector<ll> segmentTree;
vector<int> arr;

ll initialize(int idx, int l, int r){
    if (l == r){
        segmentTree[idx] = arr[l];
        return segmentTree[idx];
    }
    int mid = l + (r - l)/2;
    ll left = initialize(2*idx+1, l,mid);
    ll right = initialize(2*idx+2, mid+1,r);
    segmentTree[idx] = left + right;
    return segmentTree[idx];
}
ll query(int idx, int l, int r, int ql, int qr){
    if (l > qr || r < ql){
        return 0;
    }
    if (ql <= l && r <= qr){
        return segmentTree[idx];
    }
    int mid = l + (r-l)/2;
    ll left = query(2*idx+1,l,mid,ql,qr);
    ll right = query(2*idx+2,mid+1,r,ql,qr);
    return right + left;
}
void update(int idx, int l, int r, int index, int u){
    if (l == r && l == index){
        segmentTree[idx] = u;
        return;
    }

    int mid = l + (r - l)/2;
    if (index <= mid){
        update(2*idx+1, l, mid, index, u);
    } else {
        update(2*idx+2, mid+1, r, index, u);
    }
    segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
}
void solve() {
    int n,m;
    cin >> n >> m;
    arr.assign(n,0);
    segmentTree.assign(4*n,0);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    initialize(0,0,n-1);
    for (int i = 0; i<m; i++){
        int ins, l, r;
        cin >> ins >> l >> r;
        if (ins == 1){
            l--;
            update(0,0,n-1,l,r);
        } else {
            l--;
            r--;
            cout << query(0,0,n-1,l,r) << '\n';
        }
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