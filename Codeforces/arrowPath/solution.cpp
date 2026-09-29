#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

// bool solution(vector<string> &paths,vector<vector<bool>> &visited,int n, int x, int y,bool went){
//     if (x < 0 || x >1){
//         return false;
//     }
//     if (y<0 || y>= n){
//         return false;
//     }
//     if (y==n-1 && x == 1){
//         return true;
//     }
//     if (visited[x][y]){
//         return false;
//     }
//     visited[x][y] = true;
//     if (went){
//         if (paths[x][y] == '>'){
//             return solution(paths,visited,n,x,y+1,false);
//         } else {
//             return solution(paths,visited,n,x,y-1,false);
//         }
//     }
//     // up
//     bool up = solution(paths,visited,n,x-1,y,true);
//     if (up) return true;
//     bool down = solution(paths,visited,n,x+1,y,true);
//     if (down) return true;
//     bool right = solution(paths,visited,n,x,y+1,true);
//     if (right) return true;
//     bool left = solution(paths,visited,n,x,y-1,true);
//     if (left) return true;

//     return false;

// }
// void solve() {
//     int n;
//     cin >> n;
//     vector<string> paths(2);
//     cin >> paths[0];
//     cin >> paths[1];
//     vector<vector<bool>> visited(2,vector<bool>(n,false));
//     bool possible = solution(paths,visited,n,0,0,false);
//     if(possible){
//         cout << "YES\n";
//     } else {
//         cout << "NO\n";
//     }

// }
bool solve() {
    int n;
    cin >> n;
    vector<string> paths(2);
    cin >> paths[0];
    cin >> paths[1];
   vector<vector<array<bool, 2>>> visited(2, vector<array<bool, 2>>(n, {false, false}));
   stack<tuple<int,int,bool>> st;
   st.push({0,0,false});
   while(!st.empty()){
    auto [x,y,went] = st.top();
    st.pop();
    if (x < 0 || x >1){
        continue;
    }
    if (y<0 || y>= n){
        continue;
    }
    if (y==n-1 && x == 1){
        return true;
    }
    if (visited[x][y][went]){
        continue;
    }
    visited[x][y][went] = true;
    if (went){
        if (paths[x][y] == '>'){
            st.push({x,y+1,false});
        } else {
            st.push({x,y-1,false});
        }
        continue;
    }
    st.push({x-1,y,true});
    st.push({x+1,y,true});
    st.push({x,y+1,true});
    st.push({x,y-1,true});
   }
   return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        if(solve()){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}