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
    long long sum = 1LL * n * (n + 1) / 2;
    if (n <= 1){
        cout << "NO";
        return;
    }
    if (sum % 2 != 0){
        cout << "NO";
        return;
    }

    long long sumi = sum/2;
    vector<long long > first;
    vector<long long> second;

    for (int i = n; i>0; i--){
        if (sum < 0 ){
            cout << "NO" << endl;
            return;
        } 
        if (sum == 0) {
            break;
        }
        if (sumi >= i){
            first.push_back(i);
            sumi -= i;
        } else {
            second.push_back(i);
        }
    }
    cout << "YES" << endl;
    cout << first.size() << endl;
    for (int i = 0; i < first.size(); i++){
        cout << first[i] << " "; 
    }
    cout << endl;
    cout << second.size() << endl;
    for (int i = 0; i < second.size(); i++){
        cout << second[i] << " "; 
    }
    cout << endl;
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