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
    vector<int> query;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        query.push_back(num);
    }
    stack<pii> ansStack;
    vector<int> ans;
    for (int i = 0; i<n; i++){
        int currNum = query[i];
        while (!ansStack.empty()){
            if (currNum > ansStack.top().first){
                ans.push_back(ansStack.top().second);
                ansStack.push({currNum,i+1});
                break;
            }else {
                ansStack.pop();
            }
        }
        if (ansStack.empty()){
            ans.push_back(0);
            ansStack.push({currNum,i+1});
        }
    }
    for (int num : ans){
        cout << num << ' ';
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