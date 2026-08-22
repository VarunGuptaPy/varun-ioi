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
    bool doTheThing = true;
    for (int i = 1; i < s.size(); i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            doTheThing = false;
            cout << s;
            return;
        }
    }
    if (s[0] >= 'A' && s[0] <= 'Z'){
        s[0] = s[0] - 'A' + 'a';
    } else {
        s[0] = s[0] - 'a' + 'A';
    }
    for (int i = 1; i<s.size(); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    cout << s;
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