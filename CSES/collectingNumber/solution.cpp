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
    vector<int> numbers;
    map<int,int> pos;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
        pos[num] = i+1;
    }
    int rounds = 1;
    for (int i = 2; i<=n; i++){
        if (pos[i] < pos[i-1]){
            rounds++;
        }
    }
    cout << rounds;
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