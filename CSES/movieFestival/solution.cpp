#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

// void solve() {
//     ll n;
//     cin >> n;
//     vector<pair<ll,ll>> solve;
//     for (int i = 0; i < n; i++){
//         ll first, second;
//         cin >> first >> second;
//         solve.push_back({first,second});
//     }
//     sort(solve.begin(),solve.end());
//     ll moviesCount = 0;
//     ll prevStart=-1;
//     ll prevEnd = -1;
//     for(int i = 0; i<n; i++){
//         pair<ll,ll> current = solve[i];
//         if(prevStart<current.first && current.first >= prevEnd){
//             moviesCount++;
//             prevStart = current.first;
//             prevEnd = current.second;
//         }
//     }
//     cout << moviesCount;
    
// }
// bool valid(ll prevStart,ll prevEnd, ll currentStart){
//     if(prevStart< currentStart && currentStart >= prevEnd){
//         return true;
//     }
//     return false;
// }
// int goSolve( vector<pair<ll,ll>>& movies,int n,int movieCount, int index,ll prevStart,ll prevEnd,vector<vector<ll>>& movieDP){
//     if (index == movies.size()){
//         return 0;
//     }
//     pair<ll,ll> current = movies[index];
//     bool validity = valid(prevStart,prevEnd,current.first);
//     if (validity &&  movieDP[index][0] != -1){
//         return movieDP[index][0];
//     }
//     if (!validity && movieDP[index][1] != -1){
//         return movieDP[index][1];
//     }
//     int choose = INT_MIN;
//     int notChoose = INT_MIN;
//     int ignore = INT_MIN;

//     if (validity){
//         //choose
//         choose = 1 + goSolve(movies,n, movieCount+1,index+1,current.first,current.second,movieDP);
//         //notChoose
//         notChoose = goSolve(movies,n,movieCount,index+1,prevStart,prevEnd,movieDP);
//         // return max(choose, notChoose);
//         movieDP[index][0] = max(choose,notChoose);
//         return movieDP[index][0];
//     } else {
//         ignore = goSolve(movies,n,movieCount,index+1,prevStart,prevEnd,movieDP);
//         movieDP[index][1] = ignore;
//         return movieDP[index][1];
//     }
// }
void solve() {
    int n;
    cin >> n;

    vector<pair<ll,ll>> movies(n);

    for (auto &[start, end] : movies) {
        cin >> start >> end;
    }

    sort(movies.begin(), movies.end(),
        [](auto &a, auto &b) {
            return a.second < b.second;
        });

    ll prevEnd = 0;
    int ans = 0;

    for (auto [start, end] : movies) {
        if (start >= prevEnd) {
            ans++;
            prevEnd = end;
        }
    }

    cout << ans;
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