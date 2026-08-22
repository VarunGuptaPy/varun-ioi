#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)


void solve() {
    int l;
    cin >> l;
    int n;
    cin >> n;
    set<int> road = {0,l};
    multiset<int> gaps = {l};
    while (n--){
        int pos;
        cin >> pos;
        auto it = road.lower_bound(pos);
        int right = *it;
        it--;
        int left = *it;
        gaps.erase(gaps.find(right-left));
        gaps.insert(pos-left);
        gaps.insert(right-pos);
        road.insert(pos);
        cout << *gaps.rbegin() << " ";
    }
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