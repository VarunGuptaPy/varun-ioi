#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    vi in;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        in.push_back(num);
    }
    int m;
    cin >> m;
    vector<int> queries;
    for (int i = 0; i<m; i++){
        int num;
        cin >> num;
        queries.push_back(num);
    }
    map<int,pii> num;
    for (int i = 0; i < n; i++){
        int curr = in[i];
        int leftComparison = i+1;
        int rightComparison = n - i;
        if(num.find(curr) != num.end()){
            num[curr] = {min(leftComparison,num[curr].first),min(rightComparison,num[curr].second)};
        } else {
            num[curr] = {leftComparison,rightComparison};
        }
    }
    ll first = 0;
    ll second = 0;
    for (int i = 0; i< m; i++){
        int findElement = queries[i];
        first += num[findElement].first;
        second += num[findElement].second;
    }
    cout << first << " " << second;
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