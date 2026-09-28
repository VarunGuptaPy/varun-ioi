#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int m;
    cin >> m;
    vector<int> arr(m);
    for (int i = 0; i<m; i++){
        cin >> arr[i];
    }
    int possible = true;
    int count = 0;
    int diff = 1;
    while(arr.size() > 1){
        vector<int> newArr;
        for (int i = 0; i<arr.size()-1; i+=2){
            if (abs(arr[i] - arr[i+1]) == diff){
                newArr.push_back(min(arr[i],arr[i+1]));
            } else {
                possible = false;
                break;
            }
            if (arr[i] > arr[i+1]){
                count++;
            }
        }
        diff = diff*2;
        if (possible){
            arr = newArr;
        }
        else {
            cout << -1 << '\n';
            return;
        }
    }
    cout << count << '\n';
    
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