#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
vector<int> segmentTree;
int initialize(int idx, int start, int end){
    if (start == end){
        segmentTree[idx] = 0;
        return segmentTree[idx];
    }
    int mid = (start + end) / 2;
    segmentTree[idx] = initialize(2*idx+1,start,mid) + initialize(2*idx+2,mid+1,end);
    return segmentTree[idx];
}
int update(int idx, int start, int end, int updateIdx, int val){
    if (start == end){
        segmentTree[idx] += val;
        return segmentTree[idx];
    }
    int mid = (start + end) / 2;
    if (updateIdx <= mid){
        segmentTree[idx] = update(2*idx+1,start,mid,updateIdx,val) + segmentTree[2*idx+2];
    } else {
        segmentTree[idx] = segmentTree[2*idx+1] + update(2*idx+2,mid+1,end,updateIdx,val);
    }
    return segmentTree[idx];
}
int query(int idx, int start, int end, int l, int r) {
    // completely outside
    if (end < l || start > r) {
        return 0;
    }

    // completely inside
    if (l <= start && end <= r) {
        return segmentTree[idx];
    }

    int mid = (start + end) / 2;

    return query(2*idx+1, start, mid, l, r)
         + query(2*idx+2, mid+1, end, l, r);
}
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    segmentTree.assign(4*n,0);
    initialize(0,0,n-1);
    for (int i = 0; i<m; i++){
        int ins;
        cin >> ins;
        if (ins == 1){
            int index,val;
            cin >> index >> val;
            index--;
            update(0,0,n-1,index,val);
        } else {
            int l,r;
            cin >> l >> r;
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