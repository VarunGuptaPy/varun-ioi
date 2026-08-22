#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    vector<vector<int>> vertical;
    vector<vector<int>>  horizontal;
    int horizontalCount = 0;
    int verticalCount = 0;
    int n;
    cin >> n;
    for (int i = 0; i<n;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2){
            verticalCount++;
            vertical.push_back({x1,y1,x2,y2});
        } else {
            horizontalCount++;
            horizontal.push_back({x1,y1,x2,y2});
        }
    }
    
    int maximum = max(verticalCount,horizontalCount);
    if (verticalCount > horizontalCount){
        for (vector<int> horBar: horizontal){
            for (vector<int> verbar: vertical){
                if(verbar[1] <= horBar[1] && verbar[3] >= horBar[1] && horBar[0] <= verbar[0] && horBar[2] >= verbar[0]){
                    horizontalCount--;
                    break;
                }
            }
        }
    } else {
        for (vector<int> verbar: vertical){
            for (vector<int> horBar: horizontal){
                if(horBar[0] <= verbar[0] && horBar[2] >= verbar[0] && verbar[1] <= horBar[1] && verbar[3] >= horBar[1]){
                    verticalCount--;
                    break;
                }
            }
        }
    }
    cout << maximum + min(verticalCount,horizontalCount);
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