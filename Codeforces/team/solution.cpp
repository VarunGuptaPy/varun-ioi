#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int problems;
    cin >> problems;
    int ans = 0;
    for (int i = 0; i<problems; i++){
        int count1 = 0;
        for (int j =0; j<3; j++){
            int state;
            cin>>state;
            if(state == 1){
                count1++;
            }
        }
        if (count1 >1){
            ans++;
        }
    }
    cout << ans;
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