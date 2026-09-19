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
    unordered_map<int, vector<int>> tree;
    for (int i = 0; i<n-1; i++){
        int first,second;
        cin >> first >> second;
        tree[first].push_back(second);
        tree[second].push_back(first);
    }
    unordered_map<int,int> levels;
    queue<vector<int>> items;
    items.push({1,0,0});
    unordered_map<int,bool> visited;
    ll set1 = 0;
    long long  set2 = 0;

    while(!items.empty()){
        int node = items.front()[0];
        int level = items.front()[1];
        int set = items.front()[2];
        items.pop();
        if (!visited[node]){
            if (set == 0){
                set1++;
            } else {
                set2++;
            }
            for (int i: tree[node]){
                items.push({i,level+1,!set});
            }
            visited[node] = true;
        }

    }
    long long ans = (set1*set2) - (n-1);
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