#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> queries;

    for (int i = 0; i < m; i++) {
        int index;
        cin >> index;
        queries.push_back(index); // fixed
    }

    set<int> unique;
    vector<int> sizes(n);

    for (int i = n - 1; i >= 0; i--) {
        unique.insert(arr[i]);
        sizes[i] = unique.size();
    }

    for (int query : queries) {
        cout << sizes[query - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}