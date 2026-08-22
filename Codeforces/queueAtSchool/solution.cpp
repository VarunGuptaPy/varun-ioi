#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, t;
    cin >> n >> t;
    string queue;
    cin >> queue;
    for (int time = 0; time < t; time++){
        for (int student = 0; student < n; student++){
            if (student != (n-1) && queue[student] == 'B' && queue[student+1] == 'G'){
                swap(queue[student],queue[student+1]);
                student++;
            }
        }
    }
    cout << queue;
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