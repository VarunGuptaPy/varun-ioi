#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> elsie(n);
    set<int> used;

    for (int i = 0; i < n; i++) {
        cin >> elsie[i];
        used.insert(elsie[i]);
    }

    // Find Bessie's cards
    vector<int> bessie;

    for (int i = 1; i <= 2 * n; i++) {
        if (!used.count(i)) {
            bessie.push_back(i);
        }
    }

    // bessie is already sorted
    set<int> lowCards, highCards;

    // smallest n/2 cards -> second half
    for (int i = 0; i < n / 2; i++) {
        lowCards.insert(bessie[i]);
    }

    // largest n/2 cards -> first half
    for (int i = n / 2; i < n; i++) {
        highCards.insert(bessie[i]);
    }

    int ans = 0;

    // FIRST HALF
    // Bessie's card must be GREATER
    for (int i = 0; i < n / 2; i++) {

        auto it = highCards.upper_bound(elsie[i]);

        if (it != highCards.end()) {
            ans++;
            highCards.erase(it);
        }
    }

    // SECOND HALF
    // Bessie's card must be SMALLER
    for (int i = n / 2; i < n; i++) {

        auto it = lowCards.lower_bound(elsie[i]);

        if (it != lowCards.begin()) {
            --it;

            ans++;
            lowCards.erase(it);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}