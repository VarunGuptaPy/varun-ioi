#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
vector<int> dp;
vector<bool> visited;
int goSolve(vector<vector<int>> &tree, int currNode, int M){
    if (tree[currNode].size() == 1){
        return 2;
    }
    if (dp[currNode] != -1){
        return dp[currNode];
    }
    
    visited[currNode] = true;
    int count = 1;
    for (int i : tree[currNode]){
        if (!visited[currNode]){
            count *= goSolve(tree,i,M) % M;
        }
    }
    count++;
    count %= M;
    return dp[currNode] = count;

}
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> tree(n+1);
    for (int i = 0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    visited.assign(n+1,false);
    dp.assign(n+1,-1);
    cout << goSolve(tree, 1,m) << '\n';
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