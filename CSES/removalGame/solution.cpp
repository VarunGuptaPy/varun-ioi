#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int getMaxScore(int n, vector<int>& arr, int start, int end, int sum){
    if (start > end){
        return sum;
    }
    int firstRemoval = getMaxScore(n,arr,start+1,end,sum+arr[start]);
    int secondRemoval = getMaxScore(n,arr,start,end-1,sum+arr[end]);
    return max(firstRemoval,secondRemoval);
    
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int maxScore = getMaxScore(n,arr,0,n-1,0);
    cout << maxScore;
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