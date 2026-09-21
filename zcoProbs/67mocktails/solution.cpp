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
    vector<vector<int>> city(n,vector<int>(m,0));
    vector<int> sumS;
    vector<int> minS;
    vector<int> maxS;
    for (int i = 0; i<n; i++){
        int sumRow = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int j=0; j<m; j++){
            cin >> city[i][j];
            sumRow += city[i][j];
            maxi = max(city[i][j], maxi);
            mini = min(city[i][j], mini);
        }
        sumS.push_back(sumRow);
        minS.push_back(mini);
        maxS.push_back(maxi);
    }
    int maxItem = INT_MIN;
    for (int i = 0; i<n; i++){
        maxItem = max(maxItem, sumS[i]);
    }
    set<int> final;
    for (int i = 0; i<n ;i++){
        if (sumS[i] == maxItem){
            final.insert(minS[i]);
            
        }else {
            final.insert(maxS[i]);
        }
    }
    cout << *final.rbegin() - *final.begin();
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