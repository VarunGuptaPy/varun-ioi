#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
map<pii,bool> ans;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    vector<pii> pairs;
    for(int i = 1; i<n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        pairs.push_back({a,b});
    }
    bool present = false;
    for (int i = 1; i<=n; i++){
        if (graph[i].size() >= 3){
            present = true;
            for (int child : graph[i]){
                ans[{i,child}] = true;
            }
            break;
        }
    }
    
    if (!present){
        for (int i = 0; i<=n-2; i++){
            cout << i << '\n';
        }
    } else {
        int curr = 3;
        int zot = 0;
        for (pii i: pairs){
            if (ans[i] && zot < 3){
                cout << zot << '\n';
                zot++;
                continue;
            }
            if (ans[{i.second,i.first}] && zot < 3){
                cout << zot << '\n';
                zot++;
                continue;
            }
            cout << curr << '\n';
            curr++;
        }
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