#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i<m; i++){
        int a,b;
        cin >> a >> b;
        graph[a-1].push_back(b);
        graph[b-1].push_back(a);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> visited(n,false);
    pq.push(1);
    while(!pq.empty()){
        int front = pq.top();
        pq.pop();
        if (!visited[front-1]){
            cout << front << " ";
            visited[front-1] = true;
            for (int child: graph[front-1]){
                if (!visited[child-1]){
                    pq.push(child);
                }
            }
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