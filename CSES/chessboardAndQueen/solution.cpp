#include <bits/stdc++.h>
using namespace std;

void placeQueens(
    const vector<string>& board,
    int row,
    int& answer,
    vector<bool>& column,
    vector<bool>& diagonal1,
    vector<bool>& diagonal2
) {
    // Successfully placed one queen in every row
    if (row == 8) {
        answer++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        // Blocked square
        if (board[row][col] == '*') {
            continue;
        }

        // Main diagonal: row - col ranges from -7 to 7.
        // Add 7 to make the index range 0 to 14.
        int d1 = row - col + 7;

        // Anti-diagonal: row + col ranges from 0 to 14.
        int d2 = row + col;

        if (column[col] || diagonal1[d1] || diagonal2[d2]) {
            continue;
        }

        // Place queen
        column[col] = true;
        diagonal1[d1] = true;
        diagonal2[d2] = true;

        placeQueens(
            board,
            row + 1,
            answer,
            column,
            diagonal1,
            diagonal2
        );

        // Backtrack: remove queen
        column[col] = false;
        diagonal1[d1] = false;
        diagonal2[d2] = false;
    }
}

void solve() {
    vector<string> board(8);

    for (int row = 0; row < 8; row++) {
        cin >> board[row];
    }

    vector<bool> column(8, false);
    vector<bool> diagonal1(15, false);
    vector<bool> diagonal2(15, false);

    int answer = 0;

    placeQueens(
        board,
        0,
        answer,
        column,
        diagonal1,
        diagonal2
    );

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}