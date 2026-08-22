#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int count;
    cin >> count;

    map<int,int> coordinate;
    coordinate[0] = 0;
    coordinate[1] = 0;
    coordinate[2] = 0;
    for (int i = 0; i< count; i++){
        for (int axis = 0; axis < 3; axis++){
            int force;
            cin >> force;
            coordinate[axis] += force;
        }
    }
    if (coordinate[0] == 0 && coordinate[1] == 0 && coordinate[2] == 0){
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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