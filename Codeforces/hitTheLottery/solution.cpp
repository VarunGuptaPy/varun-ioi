#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    vector<int> notes = {1,5,10,20,100};
    int amount;
    cin >> amount;
    int count = 0;
    while (amount != 0){
        int curNote = notes[notes.size()-1];
        int divide = amount/curNote;
        count += divide;
        amount -= curNote * divide;
        notes.pop_back();
    }
    cout << count;
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