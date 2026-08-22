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
    vector<int> booksTime;
    ll sum = 0;
    int largest = 0;
    for (int i = 0; i<n;i++){
        int num;
        cin >> num;
        sum += num;
        largest = max(largest,num);

    }
    if (largest > sum - largest){
        cout << largest * 2;
    } else {
        cout << sum;
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