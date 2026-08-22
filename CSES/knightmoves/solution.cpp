#include <bits/stdc++.h>
using namespace std;

int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

// void knightMoves(
//     int y,
//     int x,
//     int moves,
//     int n,
//     vector<vector<int>>& solution
// ) {
//     // Outside the chessboard
//     if (y < 0 || y >= n || x < 0 || x >= n) {
//         return;
//     }

//     // We have already reached this square in fewer or equal moves
//     if (solution[y][x] != -1 && solution[y][x] <= moves) {
//         return;
//     }

//     // Store the better answer
//     solution[y][x] = moves;

//     // Recursively try all eight knight moves
//     for (int i = 0; i < 8; i++) {
//         knightMoves(
//             y + dy[i],
//             x + dx[i],
//             moves + 1,
//             n,
//             solution
//         );
//     }
// }

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> solution(n, vector<int>(n, -1));

    // knightMoves(0, 0, 0, n, solution);

    queue<pair<int, int>> q;
    q.push({0,0});
    solution[0][0] = 0;
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        int y = front.first;
        int x = front.second;
        for (int i = 0; i<8; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < n && newX >= 0 && newY < n && newY >= 0 && solution[newY][newX] == -1){
                solution[newY][newX] = solution[y][x] + 1;
                q.push({newY,newX});
            }
        }
    }
    for (vector<int>& row : solution) {
        for (int& cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}