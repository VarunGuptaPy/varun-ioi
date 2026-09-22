#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> paths(n);
    for (int i = 0; i<n; i++){
        cin >> paths[i];
    }
    // map<pii, vector<pii>> graph;
    // for (int i = 0; i<n; i++){
    //     for (int j = 0; j<m;j++){
    //         if (paths[i][j] == '.'){
    //             if (i != 0 && paths[i-1][j] == '.'){
    //                 graph[{i,j}].push_back({i-1,j});
    //                 graph[{i-1,j}].push_back({i,j});
    //             }
    //             if (j != 0 && paths[i][j-1] == '.'){
    //                 graph[{i,j}].push_back({i,j-1});
    //                 graph[{i,j-1}].push_back({i,j});
    //             }
    //         }
    //     }
    // }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int rooms = 0;
    vector<pii> conversion = {{0,-1},{0,+1},{-1,0},{+1,0}};
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (paths[i][j] == '.' && !visited[i][j]){
                rooms++;
                queue<pii> p;
                p.push({i,j});
                while(!p.empty()){
                    pii top = p.front();
                    p.pop();
                    if(visited[top.first][top.second]){
                        continue;
                    }
                    visited[top.first][top.second] = true;
                    for (pii child: conversion){
                        int first = top.first + child.first;
                        int second = top.second + child.second;
                        if (first < n && first >= 0 && second < m && second >= 0 && paths[first][second] == '.' && !visited[first][second]){
                            p.push({first,second});
                        }
                    }
                }
            }
        }
    }
    cout << rooms;
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