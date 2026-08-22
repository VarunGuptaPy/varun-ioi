#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
void putNum(vector<vector<int>> &ans, int y, int x,int n){
    int maxX = INT_MIN;
    int maxY = INT_MIN;
    int minX = INT_MAX;
    int minY = INT_MAX;
    vector<int> ys;
    for(int i = 0; i < y; i++){
        int currY = ans[i][x];
        ys.push_back(currY);
        maxY = max(maxY,currY);
        minY = min(minY, currY);
        
    }
    vector<int> xs;
    for(int i = 0; i < x; i++){
        int currX = ans[y][i];
        xs.push_back(currX);
        maxX = max(maxX, currX);
        minX = min(minX, currX);
    }
    
    if (min(minX,minY) == 0 ){
        int minVal = max(maxX,maxY)+1;
        for (int i = 1; i<minVal; i++){
            if (find(xs.begin(),xs.end(),i) == xs.end() && find(ys.begin(),ys.end(),i) == ys.end()){
                minVal = i;
                break;
            }
        }
        ans[y][x] = minVal;
    } else {
        ans[y][x] = 0;
    }
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n,vector<int>(n,-1));
    for(int i = 0; i<n;i++){
        ans[0][i] = i;
    }
    for(int i = 1; i <n; i++){
        for (int j = 0; j<n; j++){
            putNum(ans,i,j,n);
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
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