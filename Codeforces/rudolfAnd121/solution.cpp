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
    vector<long long> input;
    for (int i = 0; i < n; i++){
        long long num;
        cin >> num;
        input.push_back(num);
    }
    for (int i = 1; i < n-1; i++) {
    long long x = input[i-1];

    if (input[i] < 2*x || input[i+1] < x) {
        cout << "NO\n";
        return;
    }

    input[i] -= 2*x;
    input[i+1] -= x;
    input[i-1] = 0;
}

if (input[n-2] == 0 && input[n-1] == 0)
    cout << "YES\n";
else
    cout << "NO\n";
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