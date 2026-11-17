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
    vector<int> arr(n);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int maxVal = INT_MIN;
    for (int i = 0; i<n; i++){
            int divisors = 0;
            for (int j = 0; j<n; j++){
                if (arr[j] % arr[i] == 0){
                    divisors++;
                }
            }
            if (divisors > maxVal ){
                maxVal = divisors;
            }
    }
    cout << arr.size() - maxVal << '\n';
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