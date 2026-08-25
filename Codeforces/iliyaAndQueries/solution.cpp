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
    int n;
    cin >> n;
    vector<pii> queries;
    for (int i = 0; i<n; i++){
        int first,second;
        cin >> first >> second;
        queries.push_back({first,second});
    }
    vector<int> count = {0};
    int currentCount = 0;
    for (int i = 1; i<s.size();i++){
        if(s[i] == s[i-1]){
            currentCount++;
        }
        count.push_back(currentCount);
    }
    for (int i = 0; i<n; i++){
        pii currentQuery = queries[i];
        cout << count[currentQuery.second-1] - count[currentQuery.first-1] << '\n';
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