#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int rock, scissors, paper;
    cin >> rock >> scissors >> paper;

    int n =  rock + scissors + paper;
    if (scissors >= rock && scissors >= paper ){
        cout << string(n,'R');
    }
    else if (rock >= scissors && rock >= paper ){
        cout << string(n,'P');
    } else {
        cout << string(n,'S');
    }
    cout << '\n';
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