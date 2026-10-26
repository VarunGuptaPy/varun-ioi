#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)


void goSolve(vector<int> &input,int n,set<ll> &allSums, ll sum,ll index){
    if (index == n){
        allSums.insert(sum);
        return;
    }
    goSolve(input,n,allSums,sum,index+1);
    goSolve(input,n,allSums,sum+input[index],index+1);
}
void solve() {
    int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        input.push_back(num);
    }
    sort(input.begin(),input.end());
    ll sum = 0;
    for (int i = 0; i<n; i++){
        if (input[i] > sum + 1){
            cout << sum + 1; 
            return;
        } 
        sum += input[i];
    }
    cout << sum+1;
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