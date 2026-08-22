#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

// void solve() {
//     int n;
//     int sumFound;
//     cin >> n >> sumFound;
//     vector<pii> arr;
//     for (int i = 0; i<n; i++){
//         int num;
//         cin >> num;
//         arr.push_back({num,i+1});
//     }
//     sort(arr.begin(),arr.end());
//     vector<int>ans;
//     for (int i = n-1; i>=0;i--){
//         int curr = arr[i].first;
//         if (sumFound > curr){
//             int reqSum = sumFound - curr;
//             for (int j = i-1; j>=0; j--){
//                 if (reqSum > arr[j].first){
//                     reqSum-=arr[j].first;
//                     int start = 0;
//                     int end = j-1;
//                     while (start < end){
//                         int currSum = arr[start].first + arr[end].first;
//                         if (currSum == reqSum){
//                             ans.push_back(arr[start].second);
//                             ans.push_back(arr[end].second);
//                             break;
//                         } 
//                         if (currSum > reqSum){
//                             end--;
//                         } else{
//                             start++;
//                         }
//                     }
//                     if (ans.size() == 2){
//                         ans.push_back(arr[j].second);
//                         break;
//                     } else {
//                         reqSum += arr[j].first;
//                     }
//                 }
//             }
//             if (ans.size() == 3){
//                 ans.push_back(arr[i].second);
//                 break;
//             }
//         }
//     }
//     if (ans.size() == 0){
//         cout << "IMPOSSIBLE";
//         return;
//     }
//     for (int num:ans){
//         cout << num << " ";
//     }
// }

void solve(){
    int n;
    int sumReq;
    cin >> n >> sumReq;
    vector<int> arr;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    map<int,vector<int>> pairSumIndex;
    vector<int> allSum;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j<n; j++){
            int sum = arr[i] + arr[j];
            int resultant = sumReq - sum;
            if (pairSumIndex.find(resultant) != pairSumIndex.end()){
                for (int k = 0; k<pairSumIndex[resultant].size(); k+=2){
                    int firstIndex = pairSumIndex[resultant][k];
                    int secondIndex = pairSumIndex[resultant][k+1];
                    if (firstIndex != i+1 && firstIndex != j+1 && secondIndex != i+1 && secondIndex != j+1){
                        cout << firstIndex << " "<< secondIndex << " " << i+1 << " " << j+1;
                        return;
                    }
                }
            }
            pairSumIndex[sum].push_back(i+1);
            pairSumIndex[sum].push_back(j+1);
            allSum.push_back(sum);
        }
    }
    cout << "IMPOSSIBLE";
    
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