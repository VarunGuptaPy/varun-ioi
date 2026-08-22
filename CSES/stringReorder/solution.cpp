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
    unordered_map<char,int> charCount;
    for (char a : s){
        charCount[a]++;
    }
    char prev = '#';
    string ans;
    
    for (int j = 1; j<=s.size();j++){
        for (char i = 'A'; i<='Z'; i++){
            if (i != prev && charCount[i] != 0){
                charCount[i]--;
                bool possible = true;
                int maxAllowed = (s.size()-j+1)/2;
                for (char k = 'A'; k<='Z';k++){
                    if (charCount[k] > maxAllowed){
                        possible = false;
                        break;
                    }
                }
                if (possible){
                    ans.push_back(i);
                    prev = i;
                    break;
                } else {
                    charCount[i]++;
                }
            }
        }
    }
    if (ans.size() != s.size()){
        cout << -1;
        return;
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