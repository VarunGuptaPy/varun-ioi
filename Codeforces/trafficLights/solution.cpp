#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    char currentLight;
    cin >> currentLight;
    string lightArr;
    cin >> lightArr;
    if (currentLight == 'g'){
        cout << 0 << '\n';
        return;
    }
    bool gotChar = false;
    int i = 0;
    bool completedCycle = false;
    int maxTime = INT_MIN;
    int currTime = 0;
    while (i<n){
        if (lightArr[i] == currentLight && !gotChar){
            gotChar = true;
            currTime = 0;
        } else if (lightArr[i] == 'g' && gotChar && completedCycle){
            gotChar = false;
            maxTime = max(maxTime,currTime);
            currTime = 0;
            break;
        } else if (lightArr[i] == 'g' && gotChar){
            gotChar = false;
            maxTime = max(maxTime,currTime);
            currTime = 0;
        }
        if (gotChar){
            currTime++;
        }
        i++;
        if (i == n && gotChar){
            i = 0;
            // currTime++;
            completedCycle = true;
        }
    }
    cout << maxTime << '\n';
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