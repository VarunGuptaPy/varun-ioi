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
    vector<ll> boxes(n);
    vector<ll> sumBoxes(n);
    long long currSum = 0;
    long long minVal = LLONG_MAX;
    long long  maxVal = LLONG_MIN;
    for (int i = 0; i<n; i++){
        cin >> boxes[i];
        currSum += boxes[i];
        maxVal = max(maxVal,boxes[i]);
        minVal = min(minVal,boxes[i]);
        sumBoxes[i] = currSum;
    }
    long long maxDIff = maxVal - minVal;
    for (int i = 2; i<=n; i++){
        ll minVal = LLONG_MAX;
        ll maxVal = LLONG_MIN;
        if (n%i == 0){
            int prev = -1;
            for (int j = i-1; j<n; j+=i){
                ll currDif;
                if (prev == -1){
                    currDif = sumBoxes[j];
                } else {
                    currDif = sumBoxes[j] - sumBoxes[prev];
                }
                prev = j;
                minVal = min(currDif,minVal);
                maxVal = max(currDif,maxVal);
            }
            maxDIff = max(maxDIff,maxVal - minVal);
        }
    }
    cout << maxDIff << '\n';
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