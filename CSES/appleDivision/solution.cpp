#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<long long, long long>;
using vi = vector<long long>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
void goSolve(long long index, long long first, long long second,long long n,long long &mini,vector<long long> &apples){
    if(index == n){
        mini = min(mini,(max(first,second) - min(first,second)));
        return;
    }
    // go to first
    goSolve(index+1,first+apples[index],second,n,mini,apples);
    goSolve(index+1,first,second+apples[index],n,mini,apples);
}
void solve() {
    long long n;
    cin >> n;
    vector<long long> apples;
    for (long long i = 0; i<n; i++){
        long long num;
        cin >> num;
        apples.push_back(num);
    }
    long long min = INT_MAX;
    goSolve(0,0,0,apples.size(),min,apples);
    cout << min << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}