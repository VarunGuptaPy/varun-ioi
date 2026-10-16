#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
class SegmentTree {
    vector<int> tree;
    vector<int> arr;
    public:
    SegmentTree(vector<int> orArr){
        arr = orArr;
        int n= arr.size();
        tree.resize(4*n);
        initialize(0,0,n-1);
    }

    public:
    void initialize(int idx, int l, int r){
        if (l == r){
            tree[idx] = arr[l];
            return;
        }
        int mid = l + (r-l)/2;
        initialize(2*idx+1,l,mid);
        initialize(2*idx+2,mid+1,r);
        tree[idx] = max(tree[2*idx+1],tree[2*idx+2]);
    } 
    pii query(int idx, int l, int r,int val){
        if (l == r){
            return {l,tree[idx]};
        }
        int mid = l + (r-l)/2;
        if (tree[2*idx+1] >= val){
            return query(2*idx+1,l,mid,val);
        } else {
            return query(2*idx+2,mid+1,r,val);
        }
    }
    void update(int idx, int l, int r, int pos, int val){
        if (l == r && l == pos){
            tree[idx] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if (pos <= mid){
            update(2*idx+1,l,mid,pos,val);
        } else {
            update(2*idx+2,mid+1,r,pos,val);
        }
        tree[idx] = max(tree[2*idx+1],tree[2*idx+2]);
    }
};

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    SegmentTree tree = SegmentTree(arr);
    for (int i = 0; i<q; i++){
        int val;
        cin >> val;
        pii ans = tree.query(0,0,n-1,val);
        if (ans.second < val){
            cout << 0 << ' ';
        } else {
            cout << ans.first+1 << ' ';
            tree.update(0,0,n-1,ans.first,ans.second-val);
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