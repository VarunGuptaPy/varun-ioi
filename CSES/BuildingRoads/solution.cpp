#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(n+1);
    int roadTobuild = 0;
    vector<int> roadStart;
    for(int i = 1; i<=n; i++){
        if (!visited[i]){
            roadTobuild++;
            roadStart.push_back(i);
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                if (!visited[top]){
                    visited[top] = true;
                    for (int child: graph[top]){
                        if (!visited[child]){
                            q.push(child);
                        }
                    }
                }
            }
        }
    }
    cout << roadTobuild-1 << '\n';
    for (int i = 1; i<roadStart.size(); i++){
        cout << roadStart[i-1] << " " << roadStart[i] << '\n';
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