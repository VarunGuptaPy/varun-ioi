#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    vector<int> bill;
    cin >> n;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        bill.push_back(num);
    }
    vector<int> net;
    // ll totalNet = 0;
    for (int i = 0; i<n; i++){
        int budget;
        cin >> budget;
        int sub = budget - bill[i];
        net.push_back(sub);
    }
    sort(net.begin(),net.end());
    int start = 0;
    
    int end = net.size() - 1;
    int days = 0;

    int sum = 0;
    while(start<end){
        sum = net[start] + net[end];
        if (sum >= 0){
            start++;end--; days++;
            sum = 0;
        } else {
            start++;
        }
    }
    cout << days << '\n';
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