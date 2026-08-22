#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> question;

// dp[i][sum + n][previousFlipped]
vector<vector<vector<int>>> dp;

bool solution(int i, int sum, int previousFlipped) {
    if (i == n - 1) {
        return sum == 0;
    }

    int& answer = dp[i][sum + n][previousFlipped];

    if (answer != -1) {
        return answer;
    }

    /*
        question[i] may already have been flipped by the
        operation performed at index i - 1.
    */
    int currentValue = question[i];

    if (previousFlipped) {
        currentValue = -currentValue;
    }

    /*
        At this moment question[i + 1] has not been affected
        by any previous operation.
    */
    int nextValue = question[i + 1];

    // Option 1: don't flip i and i + 1
    bool notChoose = solution(i + 1, sum, 0);

    // Option 2: flip i and i + 1
    // Flipping x changes the sum by -2*x.
    int newSum = sum - 2 * currentValue - 2 * nextValue;

    bool choose = solution(i + 1, newSum, 1);

    return answer = choose || notChoose;
}

void solve() {
    cin >> n;

    question.resize(n);

    int initialSum = 0;

    for (int& value : question) {
        cin >> value;
        initialSum += value;
    }

    dp.assign(
        n,
        vector<vector<int>>(
            2 * n + 1,
            vector<int>(2, -1)
        )
    );

    if (solution(0, initialSum, 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }
}