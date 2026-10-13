#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    int count = 0;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    priority_queue<int> pq;

ll sum = 0;

for (int i = m - 1; i >= 1; i--) {

    pq.push(arr[i]);

    sum += arr[i];

    while (sum > 0) {

        int top = pq.top();

        pq.pop();

        sum -= 2LL * top;

        count++;

    }

}

sum = 0;

priority_queue<int, vector<int>, greater<int>> pq2;

for (int i = m; i < n; i++) {

    pq2.push(arr[i]);

    sum += arr[i];

    while (sum < 0) {

        int top = pq2.top();

        pq2.pop();

        sum -= 2LL * top;

        count++;

    }

}
    // till end
    cout << count << '\n';
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