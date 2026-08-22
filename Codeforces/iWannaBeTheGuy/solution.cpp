#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,p;
    cin >> n >> p;
    vector<bool> canPass(n+1,false);
    for (int i = 0; i<p; i++){
        int num;
        cin >> num;
        if (!canPass[num]){
            canPass[num] = true;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i<q; i++){
        int num;
        cin >> num;
        if (!canPass[num]){
            canPass[num] = true;
        }
    }
     for (int level = 1; level <= n; level++) {

        if (!canPass[level]) {

            cout << "Oh, my keyboard!";

            return;

        }

    }

    cout << "I become the guy.";
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