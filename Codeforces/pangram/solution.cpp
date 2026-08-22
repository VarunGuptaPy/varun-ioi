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
    string s;
    cin >> s;
    if (n < 26){
        cout << "NO";
        return;
    }
    vector<int> alphabet(26,0);
    for (int i = 0; i<n;i++){
        if (s[i] >= 'a'){
            alphabet[s[i] - 'a']++;
        } else{
            alphabet[s[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++){
        if (alphabet[i] == 0){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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