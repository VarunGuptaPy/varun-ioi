#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)


void goSolve(vector<int> &input,set<ll> &allSums, ll sum,ll index){
    if (index == input.size()){
        allSums.insert(sum);
        return;
    }
    goSolve(input,allSums,sum,index+1);
    goSolve(input,allSums,sum+input[index],index+1);
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
    set<ll> allSums;
    goSolve(input,allSums,0,0);;
    for (auto itr = ++allSums.begin(); itr != allSums.end();itr++){
        auto copyitr = itr;
        if (*(copyitr)-*(--copyitr) != 1){
            cout << *(copyitr) + 1;
            break;
        }
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