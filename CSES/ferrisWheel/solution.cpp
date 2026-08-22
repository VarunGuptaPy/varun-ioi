#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    int w;
    cin >> n >> w;
    vector<int> children;
    for (int i = 0; i<n; i++){
        int num; cin >> num;children.push_back(num);
    }
    sort(children.begin(),children.end());
    int start = 0;
    int end = n-1;
    int ans = 0;
    while (start <= end){
        int startElement = children[start];
        int endElement = children[end];
        ll sum = startElement + endElement;
        
        if (sum <= w){
            ans++;
            start++;
            end--;
        } else if (endElement <= w){
            ans++;
            end--;
        } else if (startElement <= w) {
            ans++;
            start++;
        } else if (start == end && startElement <= w){
            ans++;
            start++;
            end--;
        } else {
            end--;
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