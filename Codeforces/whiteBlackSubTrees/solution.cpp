#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

pii getSubTrees(vector<vector<int>> &graph,string color,int &count, int currentNode){
    if (currentNode == 0){
        return {0,0};
    }
    pii total;
    for (int i: graph[currentNode]){
        pii sub = getSubTrees(graph,color,count,i);
        total.first += sub.first;
        total.second += sub.second;
    }
    if (color[currentNode-1] == 'W'){
        total.second++;
    } else {
        total.first++;
    }
    if (total.first == total.second){
        count++;
    }
    return total;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);

    for (int child = 2; child <= n; child++) {
        int parent;
        cin >> parent;
        graph[parent].push_back(child);
    }

    string color;
    cin >> color;

    int count = 0;

    getSubTrees(graph, color, count, 1);

    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}