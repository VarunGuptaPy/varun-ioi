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
    int mini = INT_MAX;
    int arr[n];
    for (int i = 0; i<n;i++){
        cin >> arr[i];
        mini = min(mini,arr[i]);
    }
    vector<int> realItem;
    for (int i = 0; i<n;i++){
        if (arr[i] % mini == 0){
            realItem.push_back(arr[i]);
            arr[i] = -1;
        }
    }
    sort(realItem.begin(),realItem.end());
    int index = 0;
    for (int i = 0; i<n;i++){
        if (arr[i] == -1){
            arr[i] = realItem[index++];
        }
    }
    bool possible = true;
    for (int i = 0; i<n-1;i++){
        if (arr[i] > arr[i+1]){
            possible = false;
            break;
        }
    }
    if (possible){
        cout << "YES\n"; 
    } else {
        cout << "NO\n";
    }
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