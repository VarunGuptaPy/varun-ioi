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
    vector<int> shops(n);
    for (int i = 0; i<n; i++){
        cin >> shops[i];
    }
    sort(shops.begin(),shops.end());
    int q;
    cin >> q;
    map<int,int> solution;
    for (int i = 0;i < q; i++){
        int budget;
        cin >> budget;
        if (solution.find(budget) != solution.end()){
            cout << solution[budget] << '\n';
            continue;
        }
        int possibleIndex = -1;
        int start = 0;
        int end = n-1;
        int mid = (start+end)/2;
        while (start <= end){
            if (shops[mid] <= budget){
                possibleIndex = mid;

                start = mid+1;
            } else if (shops[mid] > budget){
                end = mid-1;
            }
            mid = (start+end)/2;
        }
        if (possibleIndex == -1){
            cout << "0\n";solution[budget] = 0;

        } else {
            cout << possibleIndex+1 << '\n';
            solution[budget] = possibleIndex + 1;
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