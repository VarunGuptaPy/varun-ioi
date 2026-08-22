#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)



static int cmp(pair<int,int> a, pair<int,int> b) {

    if (a.first != b.first)

        return a.first < b.first;   // first: ascending

    return a.second > b.second;     // second: descending

}
void solve() {
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> monsters;
    for (int i = 0; i<n;i++){
        int num;
        cin >> num;
        int rem = num % k;
        if (rem == 0){
            rem = k;
        }
        monsters.push_back({rem,i});
    }
    sort(monsters.begin(),monsters.end(),cmp);
    for (auto i = 0; i < monsters.size();i++){
        cout << monsters[i].second + 1 << " ";
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