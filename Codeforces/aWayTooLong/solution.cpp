#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    // Write the solution here.
    string word;
    cin >> word;
    if (word.length() > 10){
        int wordSize = (word.size()-2);
        string newWord = {word[0]};
        newWord += to_string(wordSize);
        newWord.push_back(word[wordSize +1]);
        cout << newWord << '\n';
    } else {
        cout << word << '\n';
    }
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