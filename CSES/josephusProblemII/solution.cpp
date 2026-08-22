#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

// void solve() {
//     int n;
//     int k;
//     cin >> n >> k;
//     vector<int> input;
//     for(int i = 1; i<=n; i++){
//         input.push_back(i);
//     }
//     auto it = input.begin();
//     vector<int> ans;
//     while (!input.empty()){
//        long long copyK = k;

//         auto copyIT = it;

//         while (copyK > 0) {

//             long long moved =

//                 min<long long>(copyK, input.end() - copyIT);

//             copyIT += moved;

//             copyK -= moved;

//             if (copyIT == input.end()) {

//                 copyIT = input.begin();

//             }

//         }

//         ans.push_back(*copyIT);

//         it = input.erase(copyIT);

//         if (it == input.end() && !input.empty()) {

//             it = input.begin();

//         }
//     }
//     for (int n: ans){
//         cout << n << " ";
//     }
// }

void solve() {
    int n;
    int k;
    cin >> n >> k;
    unordered_map<int,int> input;
    for(int i = 1; i<=n; i++){
        input[i-1] = 1;
    }
    int i = 0;
    while (!input.empty()){
        i = (k+i)%input.size();
        cout << input[i] << " ";
        input.erase(i);
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