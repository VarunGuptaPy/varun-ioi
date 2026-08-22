#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
set<string> ans;
void getPermu(string main, string curr,int n, int index){
    if (index == n){
        ans.insert(curr);
        return;
    }
    for (int i = 0; i<main.size(); i++){
        string temp = main;
        temp.erase(temp.begin()+i);
        getPermu(temp,curr+main[i],n,index+1);
    }
}
void solve() {
    string s;
    cin >> s;
    getPermu(s,"",s.size(),0);
    cout << ans.size() << "\n";
    for (const auto& element : ans) {
        std::cout << element << '\n'; // 3. Use '\n', NEVER use std::endl
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