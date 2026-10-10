#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
int digitSum(int n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    set<int> pos;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
        if (arr[i] > 9){
            pos.insert(i);
        }
    }
    for (int i = 0; i<q; i++){
        int ins;
        cin >> ins; 
        if (ins == 1) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    while (true) {
        auto it = pos.lower_bound(l);

        if (it == pos.end() || *it > r) {
            break;
        }

        int idx = *it;
        arr[idx] = digitSum(arr[idx]);

        if (arr[idx] < 10) {
            pos.erase(it);
        }

        l = idx + 1;  
    }
} else {
            int index;
            cin >> index;
            cout << arr[index-1] << ' ';
        }
    }
    cout << '\n';
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