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
    vector<int> entries(n);
    bool zeroPresent = false;
    int lastzero = -2;
    vector<int> lastZeroVec(n);
    for (int i = 0; i<n; i++){
        cin >> entries[i];
        if (entries[i] == 0){
            lastzero = i;
            zeroPresent = true;
        }
        lastZeroVec[i] = lastzero;
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