#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants;
    for (int i = 0; i<n; i++){
        int num; cin >> num; applicants.push_back(num);
    }
    vi appartments;
    for (int i = 0; i<m; i++){
        int num; cin >> num; appartments.push_back(num);
    }
    sort(applicants.begin(),applicants.end());
    sort(appartments.begin(),appartments.end());
    int i = 0; int j = 0;
    int ans = 0;
    
    while (i < n && j < m){
        int currAppartment = appartments[j];
        int currApplicant = applicants[i];
        int diff = currAppartment-currApplicant;
        if (abs(diff) <= k){
            ans++;
            i++;
            j++;
        } else if (diff < 0){
            j++;
        } else {
            i++;
        }
    }
    cout << ans;
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