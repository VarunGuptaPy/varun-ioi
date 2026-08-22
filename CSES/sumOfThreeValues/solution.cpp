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
    int sumNum;
    cin >> sumNum;
    vector<pii> val;
    for (int i = 0; i<n;i++){
        int num;
        cin >> num;
        val.push_back({num,i});
    }
    vector<pii> valCopy = val;
    sort(val.begin(),val.end());
    vector<pii> ans = {};
    for (int i = 0; i<n; i++){
        int start = i+1;
        int end = n-1;
        int sumNum2 = sumNum - val[i].first;
        bool gotANS = false;
        while (start < end){
            int sum = val[start].first + val[end].first;
            if (sum == sumNum2){
                gotANS = true;
                break;
            } else if (sum > sumNum2){
                end--;
            } else {
                start++;
            }
        }
        if (gotANS ){
            ans.push_back(val[i]);
            ans.push_back(val[start]);
            ans.push_back(val[end]);
            break;
        } 
    }
    if (ans.size() == 0){
        cout <<"IMPOSSIBLE";
        return;
    }
    for (pii curr: ans){
        cout << curr.second+1 << " ";
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