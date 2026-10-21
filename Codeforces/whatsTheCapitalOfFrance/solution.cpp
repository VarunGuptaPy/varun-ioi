#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class DSU {
    unordered_map<int, int> parent;

public:
    int find(int x) {
        if (x < 0) return -1;

        auto it = parent.find(x);

        if (it == parent.end())
            return x;

        return it->second = find(it->second);
    }

    void occupy(int x) {
        parent[x] = find(x - 1);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<bool> changed(n, false);

    unordered_set<int> present;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        present.insert(arr[i]);
    }

    DSU dsu;

    vector<int> values(present.begin(), present.end());
    sort(values.begin(), values.end());

    for (int x : values) {
        dsu.occupy(x);
    }

    for (int i = 0; i < n - 1; i++) {

        if (arr[i] < arr[i + 1]) {
            int changeValue = dsu.find(arr[i + 1] - 1);

            if (changeValue > arr[i])
                arr[i] = changeValue;
            else
                arr[i] = arr[i + 1] - 1;

            changed[i] = true;
        }

        if (arr[i] > arr[i + 1]) {
            int changeValue = dsu.find(arr[i] - 1);

            if (changeValue > arr[i + 1])
                arr[i + 1] = changeValue;
            else
                arr[i + 1] = arr[i] - 1;

            changed[i + 1] = true;
        }

        if (arr[i] == arr[i + 1] && changed[i]) {
            arr[i]--;
        }
    }

    int ans = 0;

    for (int v : arr) {
        ans |= v;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}