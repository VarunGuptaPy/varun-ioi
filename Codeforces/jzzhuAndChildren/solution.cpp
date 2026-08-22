#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m;
    cin >> n >> m;
    queue<int> children;
    vector<int> candies;
    for (int i = 1; i<=n; i++){
        int candy;
        cin >> candy;
        candies.push_back(candy);
        children.push(i);
    }
    while (children.size() != 1){
        int front = children.front();
        candies[front-1] -= m;
        if (candies[children.front()-1] < 1){
            children.pop();
        } else {
            children.pop();
            children.push(front);
        }
    }
    cout << children.front();
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