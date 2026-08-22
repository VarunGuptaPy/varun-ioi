#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string borzeCode;
    cin >> borzeCode;
    string num;
    int n = borzeCode.size();
    for (int i = 0; i < n; i++){
        if (borzeCode[i] == '.'){
            num.push_back('0');
        } else if (borzeCode[i] == '-' && borzeCode[i+1] == '.'){
            num.push_back('1');
            i++;
        } else if (borzeCode[i] == '-' && borzeCode[i+1] == '-') {
            num.push_back('2');
            i++;
        }
    }
    cout << num;
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