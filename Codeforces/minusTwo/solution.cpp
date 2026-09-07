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
    vector<int> items(n);
    for (int i = 0; i<n; i++){
        cin >> items[i];
    }
    int oddCount = 0;
    int evenEquals = 0;
    int fourMultiples = 0;
    for (int i = 0; i<n;i++){
        int num = items[i];
        if (num == 1) {
            oddCount++;
        } else if (num%4==0){
            fourMultiples++;
        } else if (num%2 == 0){
            evenEquals++;
        } else {
            oddCount++;
        }
    }
    cout << max(oddCount,max(evenEquals,fourMultiples)) << '\n';

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