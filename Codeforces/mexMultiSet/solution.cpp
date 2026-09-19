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
    int countZero = 0;
    vector<int> nums(n);
    for (int i = 0; i<n;i++){
        cin >> nums[i];
        if (nums[i] == 0){
            countZero++;
        } 
    }
    if (countZero == 1){
        cout << "NO\n";
        return;
    }
    string things = "";
    bool doneA = false;
    for (int i = 0; i<n; i++){
        if (nums[i] == 0 && doneA){
            things.push_back('B');
        } else if (nums[i] == 0 && !doneA){
            things.push_back('A');
            doneA = true;
        } else if (nums[i] != 0){
            things.push_back('C');
        }
    }
    cout << "YES\n";
    cout << things << '\n';
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