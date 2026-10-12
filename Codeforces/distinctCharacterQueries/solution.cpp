#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

vector<int> segmentTree;
int  initializeSegment(string s, int idx,int l,int r){
    if (l == r){

        int num = 1 << (s[l]-'a');
        segmentTree[idx] = num;
        return segmentTree[idx];
    }
    int mid = (l+r)/2;
    int val1 = initializeSegment(s,2*idx+1, l,mid);
    int val2 = initializeSegment(s,2*idx+2,mid+1,r);
    segmentTree[idx]= val1 | val2;
    return segmentTree[idx];
}

int update(char updateS, int idx, int l, int r, int index) {

    // Leaf
    if (l == r && l == index) {
        segmentTree[idx]  = 1 << (updateS - 'a');

        return segmentTree[idx];
    }

    int mid = (l + r) / 2;

    if (index >= l && index <= mid) {
        update(updateS, 2*idx+1, l, mid, index);

    } else {
        update(updateS, 2*idx+2, mid+1, r, index);
    }


    segmentTree[idx] = segmentTree[2*idx+1] | segmentTree[2*idx+2];

    return segmentTree[idx];
}

int query(int idx, int l, int r, int ql, int qr) {

    // 1. No overlap
    if (r < ql || l > qr) {
        return 0;
    }

    // 2. Complete overlap
    if (ql <= l && r <= qr) {
        return segmentTree[idx];
    }

    // 3. Partial overlap
    int mid = (l + r) / 2;

    int left =
        query(2*idx+1, l, mid, ql, qr);

    int right =
        query(2*idx+2, mid+1, r, ql, qr);

    // union

    return left | right;
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    segmentTree.resize(4*n);
    initializeSegment(s,0,0,s.size()-1);
    int q;
    cin >> q;
    for (int i = 0; i<q; i++){
        int ins;
        cin >> ins;
        if (ins == 1){
            int u;
            char a;
            cin >> u >> a;
            update(a,0,0,n-1,u-1);
        }else {
            int l,r;
            cin >> l >> r;
            int c= query(0,0,n-1,l-1,r-1);
            cout << __builtin_popcount(c) << '\n';
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