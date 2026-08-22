#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int students;
    int puzzleCount;
    cin >> students >> puzzleCount;
    vi puzzle;
    for (int i = 0; i< puzzleCount; i++){
        int num;
        cin >> num;
        puzzle.push_back(num);
    }
    sort(puzzle.begin(),puzzle.end());
    int start = 0;
    int end = students-1;
    int mini = INT_MAX;
    while (end < puzzle.size()){
        int diff = puzzle[end] - puzzle[start];
        mini = min(mini, diff);
        start++;
        end++;
    }
    cout << mini;
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