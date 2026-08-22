#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
vector<string> grayCode(int n){
    if (n == 1){
        return {"0","1"};
    }
    vector<string> first;
    vector<string> second;
    vector<string> prev = grayCode(n-1);
    int size = prev.size();
    for (int i = 0; i<size; i++){
        first.push_back("0"+prev[i]);
        second.push_back("1"+prev[size-i-1]);
    }
    first.reserve(first.size() + first.size());
    first.insert(first.end(), second.begin(), second.end());
    return first;
}
void solve() {
    int n;
    cin >> n;
    vector<string> ans = grayCode(n);
    int size = ans.size();
    for (int i = 0; i < size; i++){
        cout << ans[i] << endl;
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