#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string str;
    cin >> str;
    map<char,long long> mapChar;
    for (long long i = 0; i<str.size(); i++){
        mapChar[str[i]]++;
    }
    long long min = INT_MAX;
    char minCh;
    int oddCount = 0;
    for (const auto& [key, value] : mapChar) {
        if (value % 2 != 0 && oddCount>0){
            cout << " NO SOLUTION";
            return;
        }
        if (value % 2 != 0){
            minCh = key;
            oddCount++;
        }
        // if (value != 1 && value %2 != 0){
        //     cout << "NO SOLUTION";
        //     return;
        // }
        if (value < min){
            min = value;
            minCh = key;
        }
    } 
    string ans;
    if (oddCount){
        int val = mapChar[minCh];
        ans = minCh;
        val--;
        ans = string(val/2,minCh) + ans + string(val/2,minCh);

    }
    for (const auto& [key, value] : mapChar) {
        if (key != minCh || value %2 ==0){
            long long valHalf = value/2;
            ans = string(valHalf,key) + ans + string(valHalf,key);
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