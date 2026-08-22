#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
bool isMIN(int a, int b, int c){
    return (a <= b+c && b <= a+c && c <= b+a);
}
void solve() {
    int a,b,c;
    cin >> a >> b >> c;
    while (!isMIN(a, b, c)){
        if (a > b + c){
            a = b+c;
        } else if (b > a + c){
            b = a + c;
        } else if (c > a + b){
            c = a + b;
        } else {
            break;
        }
    }
    cout << max(a,max(b,c)) - min(a,min(b,c)) << '\n';
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