#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void countReachableRoot(vector<vector<int>>& rootedTree, vector<int>& haveCat, int maxCat,int currentCat, int& count,int current,int parent){
    if (haveCat[current-1] && currentCat == 0){
        return;
    }
    
    if (haveCat[current-1]){
        currentCat--;
    }
    if (!haveCat[current-1]){
        currentCat = maxCat;
    }
    
    bool isLeaf = true;
    for (int i : rootedTree[current-1]){
        if (i == parent){
            continue;
        }
        isLeaf = false;
        countReachableRoot(rootedTree,haveCat,maxCat,currentCat,count,i,current);
    }
    if (isLeaf){
        count++;
    }
}
void solve() {
    int n,maxCat;
    cin >> n >> maxCat;
    vector<int> haveCat(n);

    for (int i = 0; i < n; i++){
        cin >> haveCat[i];
    }

    vector<vector<int>> rootedTree(n);
    for (int i = 1; i<n; i++){
        int a,b;
        cin >> a >> b;
        rootedTree[a-1].push_back(b);
        rootedTree[b-1].push_back(a);
    }

    int count = 0;
    countReachableRoot(rootedTree,haveCat,maxCat,maxCat,count,1,-1);
    cout << count;
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