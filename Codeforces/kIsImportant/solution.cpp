#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
pii getItem(vector<int> arr, vector<bool> visited, int index){
    if (visited[index] == false){
        return {arr[index],index};
    }
    if (index == arr.size()){
        return {-1,-1};
    }
    return getItem(arr,visited,index+1);
}
int maxScore(vector<int> &arr,map<int,vector<int>>  &dp,vector<bool> &visisted,int lastRemoved, int size, int k){
    if (size<k){
        return 0;
    }
    if (dp[lastRemoved][size] != -1){
        return dp[lastRemoved][size];
    }
    int score = 0;
    pii atk = getItem(arr,visisted,k-1);
    int score1 = 0;
    if (atk.first != -1){
        visisted[atk.second] = true;
        score1 = atk.first +  maxScore(arr,dp,visisted,atk.first,size-1,k);
        visisted[atk.second] = false;
    }
    pii atm = getItem(arr,visisted,size-k);
    int score2 = 0;
    if (atm.first != -1){
        visisted[atm.second] = true;
        score2 = atm.first + maxScore(arr,dp,visisted,atm.first,size-1,k);
        visisted[atm.second] = false;
    }
    score = max(score1,score2);
    return dp[lastRemoved][size] = score;
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int,vector<int>> dp;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
        dp[arr[i]] = vector<int> (n+1,-1);
    }
    dp[0] = vector<int>(n+1,-1);
    vector<bool> visisted(n,false);
    int score = maxScore(arr,dp,visisted,0,n,k);
    cout << score << '\n';
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