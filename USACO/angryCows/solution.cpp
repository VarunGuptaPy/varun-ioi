#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n,k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    map<int,int> diff;
    for (int i = 0; i<n-1;i++){
        diff[arr[i+1] - arr[i]]++;
    }
    int cowsNeeded = n;
    for(auto& [key,value]: diff){
        cowsNeeded-=value;
        if (cowsNeeded == k){
            cout << key;
            return;
        }
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