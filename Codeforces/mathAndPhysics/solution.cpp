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
    vector<int> arr;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    while (arr.size() > 1){
        int maxIndex = max_element(all(arr)) - arr.begin();
        if (arr[maxIndex] <= 2) {
            cout << -1 << '\n';
            return;
        }
        if (maxIndex == 0){
            arr[1] += arr[maxIndex] -1;
        } else if (maxIndex == arr.size()-1){
            arr[arr.size()-2]+= arr[maxIndex] -1;
        } else {
            if(arr[maxIndex+1] >= arr[maxIndex-1]){
                arr[maxIndex+1] += arr[maxIndex]-1;
                arr[maxIndex-1] += 1;
            } else {
                arr[maxIndex-1] += arr[maxIndex]-1;
                arr[maxIndex+1] += 1;
            }
        }
        arr.erase(arr.begin() + maxIndex);
    }
    cout << arr[0] << '\n';
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