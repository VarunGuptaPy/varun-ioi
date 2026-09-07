#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

bool isLucky(int n){
    while (n!=0){
        if (n%10 != 4 && n%10 != 7){
            return false;
        }
        n/=10;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++){
        if (isLucky(i) && n%i==0){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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