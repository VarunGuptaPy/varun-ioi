#include <bits/stdc++.h>
using namespace std;

// int getMaxPages(vector<int>& price,
//                 vector<int>& pages,
//                 int index,
//                 int moneyLeft,
//                 vector<vector<int>>& dp) {

//     if (index == price.size()) {
//         return 0;
//     }

//     if (dp[index][moneyLeft] != -1) {
//         return dp[index][moneyLeft];
//     }

//     // Don't choose this book
//     int notChoose = getMaxPages(
//         price,
//         pages,
//         index + 1,
//         moneyLeft,
//         dp
//     );

//     // Choose this book
//     int choose = 0;

//     if (price[index] <= moneyLeft) {
//         choose = pages[index] +
//                  getMaxPages(
//                      price,
//                      pages,
//                      index + 1,
//                      moneyLeft - price[index],
//                      dp
//                  );
//     }

//     return dp[index][moneyLeft] = max(choose, notChoose);
// }

// void solve() {
//     int n, maxPrice;
//     cin >> n >> maxPrice;

//     vector<int> price(n);
//     vector<int> pages(n);

//     for (int& x : price)
//         cin >> x;

//     for (int& x : pages)
//         cin >> x;

//     vector<vector<int>> dp(
//         n,
//         vector<int>(maxPrice + 1, -1)
//     );

//     cout << getMaxPages(
//         price,
//         pages,
//         0,
//         maxPrice,
//         dp
//     );
// }

void solve(){
    int n, maxPrice;
    cin >> n >> maxPrice;

    vector<int> price(n);
    vector<int> pages(n);

    for (int& x : price)
        cin >> x;

    for (int& x : pages)
        cin >> x;
    
    vector<int> dp(maxPrice+1,0);
    for (int i = 0; i<n; i++){
        int currPrice = price[i];
        int currPage = pages[i];
        for (int j = maxPrice; j>=currPrice;j--){
            dp[j] = max(dp[j],currPage + dp[j-currPrice]);
        }
    }
    cout << dp[maxPrice];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}