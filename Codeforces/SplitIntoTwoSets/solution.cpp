// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// using vi = vector<int>;

// #define all(x) begin(x), end(x)
// #define rall(x) rbegin(x), rend(x)

// bool findLoop(int node,vector<int>& color , vector<vector<int>>& graph, vector<bool>& visited) {
//     vector<int> child = graph[node];
//     visited[node] = true;
//     auto itr = child.begin();
//     while (itr != child.end()){
//         int i = *itr;
//         if (visited[i] && color[i] == color[node]){
//             return false;
//         } else if (visited[i]){}else if (!visited[i]){
//             if (findLoop(i,node,findingNode,graph,visited)){
//                 return true;
//             }
//         }
//         itr++;
//     }
//     return false;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<vector<int>> graph(n+1);
//     for (int i = 0; i<n; i++){
//         int a,b;
//         cin >> a >> b;
//         int size = graph[a].size();
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     vector<bool> visited(n+1);
//     vector<int> color(n+1);
//     for (int i = 1; i<=n; i++){
//         if (visited[i]) continue;
//         if (!findLoop(i,-1,i,graph,visited)){
//             cout << "NO\n";
//             return;
//         }
//     }
//     cout << "YES\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int test_cases = 1;
//     cin >> test_cases;

//     while (test_cases--) {
//         solve();
//     }

//     return 0;
// }