#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string s1; 
    cin >> s1;
    string s2;
    cin >> s2;
    for (int i = 0; i<s1.size(); i++){
        int curr1 = 0;
        if (s1[i] >= 'a' && s1[i] <= 'z'){
            curr1 = s1[i] - 'a' + 1;
        } else {
            curr1 = s1[i] - 'A' +1;
        }
        int curr2 = 0;
        if (s2[i] >= 'a' && s2[i] <= 'z'){
            curr2 = s2[i] - 'a' + 1;
        } else {
            curr2 = s2[i] - 'A' +1;
        }
        if (curr1 < curr2){
            cout << -1;
            return;
        } else if (curr1 > curr2){
            cout << 1;
            return;
        }

    }
    cout << 0;
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