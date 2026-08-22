#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    ifstream cin("circlecross.in");
    ofstream cout("circlecross.out");
    string path;
    cin >> path;
    unordered_map<string,int> pairs;
    int ans = 0;
    for (int i = 0; i<(path.size()-1); i++){
        string pair = {path[i],path[i+1]};
        pairs[pair]++;
        if (pairs[pair] > 1){
            ans++;
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