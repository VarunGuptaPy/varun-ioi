#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
bool isBeautiful(int year){
    set<int> digit;
    int total = 0;
    while (year != 0){
        total++;
        digit.insert(year%10);
        year/=10;
    }
    return digit.size() == total;
}
void solve() {
    int n;
    cin >> n;
    while(true){
        n++;
        if (isBeautiful(n)){
            cout << n;
            return;
        }
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