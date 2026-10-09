#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> xors;
    int currXor = 0;
    for (int i = 0; i<n; i++){
        cin >> nums[i];
        currXor ^= nums[i];
        xors.push_back(currXor);
    }
    string bin;
    cin >> bin;
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i<n; i++){
        if (bin[i] == '1'){
            xor1 ^= nums[i];
        } else {
            xor2 ^= nums[i];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i<q;i++){
        int ins;
        cin >> ins;
        if (ins == 1){
            int l,r;
            cin >> l >> r;
            if (l == 1){
                xor1 ^= xors[r - 1];
                xor2 ^= xors[r-1];
                continue;
            }
            xor1 ^= xors[r-1] ^ xors[l-2];
            xor2 ^= xors[r-1] ^ xors[l-2];
        } else {
            int xored;
            cin >> xored;
            if (xored == 1){
                cout << xor1 << ' ';
            } else {
                cout << xor2 << ' ';
            }
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