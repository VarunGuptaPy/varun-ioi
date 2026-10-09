#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
int ansCount = 0;
int getAns(vector<vector<int>> &tree, vector<bool> &visited, int currNode){
    int currCount = 1;
    visited[currNode] = true;
    for (int i : tree[currNode]){
        if(!visited[i]){
            int ans = getAns(tree,visited,i);
            if (ans % 2 == 0){
                ansCount++;
            } else{
                currCount += ans;
            }
        }
    }
    return currCount;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1);
    for (int i = 0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<bool> visited(n+1);
    int ans = getAns(tree, visited, 1);
    if (ans % 2 == 0){
        cout << ansCount;
    } else {
        cout << -1;
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