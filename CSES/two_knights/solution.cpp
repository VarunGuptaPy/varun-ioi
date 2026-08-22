#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    const int dx[8] = {1, -1, 2, 2, -2, -2, 1, -1};
    const int dy[8] = {-2, -2, -1, 1, 1, -1, 2, 2};

    for (int size = 1; size <= n; size++) {
        ll count = 0;
        ll visitedCount = 0;
        long long ans = 0.5 * (pow(size,4))-4.5*(pow(size,2))+12*size-8;
        cout << ans << endl;
        // vector<vector<bool>> vis(size, vector<bool>(size, false));

        // for (int x = 0; x < size; x++) {
        //     for (int y = 0; y < size; y++) {
        //         vis[y][x] = true;
        //         visitedCount++;

        //         ll totalAdded = 1LL * size * size - visitedCount;

        //         for (int move = 0; move < 8; move++) {
        //             int nx = x + dx[move];
        //             int ny = y + dy[move];

        //             if (nx >= 0 && nx < size &&
        //                 ny >= 0 && ny < size &&
        //                 !vis[ny][nx]) {
        //                 totalAdded--;
        //             }
        //         }

        //         count += totalAdded;
        //     }
        // }

        // cout << count << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}