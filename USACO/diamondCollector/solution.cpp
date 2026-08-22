#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> diamonds;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        diamonds.push_back(num);
    }
    int first = 0;
    int second = 0;
    int current = 1;
    sort(diamonds.begin(),diamonds.end());
    for (int i = 1; i < n ; i++ ){
        if (diamonds[i] - diamonds[i-1] <= k){
            current++;
            
        } else {
            if (current > first){
                second = first;
                first = current;
            } else if (current > second){
                second = current;
            }
            current = 1;
        }
    }
    cout << first + second;
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