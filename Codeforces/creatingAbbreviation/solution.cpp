#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m;
    cin >> n >> m;
    map<char,bool> present;
    for (int i = 0; i <n; i++){
        string s;
        cin >> s;
        present[s[0]] = true;
    }
    
    vector<string> mS;
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        mS.push_back(s);
    }
    for (string s:mS){
        for(char ch: s){
            if (!present[ch - 'A' + 'a']){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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