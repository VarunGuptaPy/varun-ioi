#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
static int cmp(pii a, pii b){
    return b.second < a.second;
}
void solve() {
    ll n;
    int m;
    cin >> n >> m;
    vector<pii> containerAndMatches;
    for (int i = 0; i < m; i++){
        int matchBox;
        int matches;
        cin >> matchBox >> matches;
        containerAndMatches.push_back({matchBox,matches});
    }
    sort(containerAndMatches.begin(),containerAndMatches.end(),cmp);
    ll totalMatches = 0;
    for (int i = 0; i<m; i++){
        pii curr = containerAndMatches[i];
        if (curr.first < n){
            n -= curr.first;
            totalMatches += curr.second * curr.first;
        } else {
            totalMatches += n * curr.second;
            n = 0;
            break;
        }
    }
    cout << totalMatches;
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