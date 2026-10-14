#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

vector<ll> segment;
vector<int> arr;
int ans = 0;
ll initialize(int idx, int l, int r,int k){
    if(l == r){
        segment[idx] = arr[l];
        return arr[l];
    }
    int mid = l + (r-l)/2;
    ll left = initialize(2*idx+1,l,mid,k);
    ll right = initialize(2*idx+2,mid+1,r,k);
    segment[idx] = segment[2*idx+1] + segment[2*idx+2];
    if (r-l+1 > k && segment[idx]%k == 0){
        ans++;
    }
    return left+right;

}
void solve() {
    int n,k;
    cin >> n >> k;
    arr.clear();
    segment.clear();
    ans = 0;
    arr.resize(n);
    segment.resize(4*n);
    for (int i = 0; i<n;i++){
        cin >> arr[i];
    }
    initialize(0,0,n-1,k);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}