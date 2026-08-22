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
    vector<int> input;
    for (int i = 0; i<n;i++){
        int num;
        cin >> num;
        input.push_back(num);
    }
    multiset<int> ans;
    for (int num: input){
        auto it = ans.upper_bound(num);
        if (it != ans.end()){
            ans.erase(it);
        } 
        ans.insert(num);
    }
    cout << ans.size();
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