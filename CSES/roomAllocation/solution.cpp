
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

    vector<tuple<int, int, int>> customers;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    sort(all(customers));

    priority_queue<
        pii,
        vector<pii>,
        greater<pii>
    > pq;

    vi ans(n);
    int rooms = 0;

    for (auto [start, end, idx] : customers) {
        int room;

        if (!pq.empty() && pq.top().first < start) {
            room = pq.top().second;
            pq.pop();
        } else {
            rooms++;
            room = rooms;
        }

        ans[idx] = room;
        pq.push({end, room});
    }

    cout << rooms << '\n';

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
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
