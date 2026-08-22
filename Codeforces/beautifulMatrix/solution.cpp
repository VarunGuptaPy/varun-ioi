#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int x;
    int y;
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            int num;
            cin >> num;
            if (num == 1){
                x = j;
                y = i;
            }
        }
    }
    int moves = 0;
    while (x != 3){
        if (x < 3){
            x++;
            moves++;
        } else {
            x--;
            moves++;
        }
    }
    while (y != 3) {
        if (y < 3){
            y++;
            moves++;
        } else {
            y--;
            moves++;
        }
    }
    cout << moves << '\n';
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