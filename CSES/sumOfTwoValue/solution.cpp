#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

static int cmp(pii a, pii b){
    return a.first < b.first;
}
void solve() {
    int n;
    ll s;
    vector<pii> valuesIndex;
    cin >> n >> s;
    for (int i = 0; i < n ; i++){
        int num;
        cin >> num;
        valuesIndex.push_back({num,i+1});
    }
    sort(valuesIndex.begin(),valuesIndex.end(),cmp);
    int start = 0;
    int end = n-1;
    while (start < end){
        ll sum = valuesIndex[start].first + valuesIndex[end].first;
        if (sum == s){
            cout << valuesIndex[start].second << " " << valuesIndex[end].second; 
            return;
        } else if (sum < s){
            start++;
        } else {
            end--;
        }
    }
    cout << "IMPOSSIBLE";
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