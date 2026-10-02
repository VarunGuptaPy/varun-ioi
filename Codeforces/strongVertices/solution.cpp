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
    vector<int> a(n);
    vector<int> b(n);
    vector<pii> sum1;
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    for (int i = 0; i<n;i++){
        cin >> b[i];
    }
    for (int i = 1; i<=n; i++){
        int sub = a[i-1] - b[i-1];
        sum1.push_back({sub,i});
    }
    sort(sum1.begin(),sum1.end());
    int count = 0;
    vector<int> out;
    int index=n-1;
    while(sum1[index].first == sum1[n-1].first){
        count++;
        out.push_back(sum1[index].second);
        index--;
    }
    cout << count << '\n';
    for (int index =out.size()-1; index >= 0; index--){
        cout << out[index] << " ";
    }
    cout << '\n';
    
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