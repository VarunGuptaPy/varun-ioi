#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

// void solve() {
//     int n;
//     cin >> n;
//     unordered_map<int,int> numMap;
//     for (int i = 0; i<n; i++){
//         int a;
//         int b;
//         cin >> a >> b;
//         for (int j = a; j<=b; j++){
//             numMap[j]++;
//         }
//     }
//     auto itr = numMap.begin();
//     int maxi = INT_MIN;
//     for(itr =itr; itr!= numMap.end(); itr++)
//         maxi = max(itr -> second,maxi);
//     cout << maxi;
// }
// static int cmp(pii a, pii b){
//     return abs(a.first - a.second) > abs(b.first - b.second);
// }
void solve() {
    int n;
    cin >> n;
    set<ll> first;
    unordered_map<int,bool> isArrival;
    for (int i = 0; i<n; i++){
        ll a;
        ll b;
        cin >> a >> b;
        first.insert(a);
        isArrival[a]= true;
        first.insert(b);
        isArrival[b] = false;
    }
    int currCustomer = 0;
    int maxi = 0;
    // while(!first.empty() && !second.empty()){
    //     if (first.begin() != first.end() && *first.begin() == i){
    //         currCustomer++;
    //         first.erase(first.begin());
    //         maxi = max(maxi,currCustomer);
    //     } else if (second.begin() != second.end() && *second.begin() == i){
    //         currCustomer--;
    //         second.erase(second.begin());
    //         maxi = max(maxi,currCustomer);
    //     }
    //     i++;
    // }
    
    for (ll i: first){
        if (isArrival[i]){
            currCustomer++;
            maxi = max(currCustomer,maxi);
        } else {
            currCustomer--;
        }
    }
    cout << maxi;
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