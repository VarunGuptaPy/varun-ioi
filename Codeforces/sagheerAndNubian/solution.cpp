#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, budget;
    cin >> n >> budget;
    vector<int> base;
    for (int i = 0; i<n;i++){
        int num;
        cin >> num;
        base.push_back(num);
    }
    int start = 0;
    int end = n;
    auto isPossible = [&](int k) -> bool {
        int amount = 0;
        for (int i = 0; i <= k; i++){
            amount += base[i] + i*k;
            if (amount > budget){
                return false;
            }
        }
        return true;
    };
    while (start <= end){
        int mid = start+(end-start)/2;
        if (isPossible(mid)){
            start = mid;
        } else {
            end = mid-1;
        }
    }
    cout << start;
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