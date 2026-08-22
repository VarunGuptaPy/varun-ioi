#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string s;
    cin >> s;
    if (s.size() < 7){
        cout << "NO";
        return;
    }
    int straight1 = 0;
    int straight2 = 0;
    for (char pos: s){
        
        if (pos == '1'){
            straight1++;
            straight2 = 0;
        }
        if (pos == '0'){
            straight2++;
            straight1 = 0;
        }
        if (straight1 >= 7 || straight2 >= 7){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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