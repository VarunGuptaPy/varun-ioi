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
    vector<int> queue;
    for (int i = 0; i<n;i++){
        int num;
        cin >> num;
        queue.push_back(num);
    }
    sort(queue.begin(),queue.end());
    int timePassed = 0;
    int ans = 0;
    for (int i = 0; i<n; i++){
        int curr = queue[i];
        if (timePassed <= curr){
            timePassed += curr;
            ans += 1;
        }
    }
    cout << ans;
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