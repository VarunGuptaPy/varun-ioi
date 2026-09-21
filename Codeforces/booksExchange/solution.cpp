#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int getDays(vector<int> &changes, int originalNum, int currentNum){
    if (originalNum == currentNum){
        return 1;
    }
    int days = 1 + getDays(changes,originalNum,changes[currentNum-1]);
    return days;
}

void solve() {
    int n;
    cin >> n;
    vector<int> changes(n);
    for (int i = 0; i<n ;i++){
        cin >> changes[i];
    }
    vector<int> totalDays(n);
    for (int i = 1; i<=n; i++){
        totalDays[i-1] = getDays(changes, i, changes[i-1]);
    }
    for (int day: totalDays){
        cout << day << " ";
    }
    cout << '\n';
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