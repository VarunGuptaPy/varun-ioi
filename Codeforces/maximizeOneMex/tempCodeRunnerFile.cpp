#include <bits/stdc++.h>
using namespace std;

int getMex(vector<int>& a, int len) {
    vector<bool> present(a.size() + 1, false);

    for (int i = 0; i < len; i++) {
        present[a[i]] = true;
    }

    for (int i = 0; i <= a.size(); i++) {
        if (!present[i])
            return i;
    }

    return a.size();
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int len = n - k + 1;

    int best = getMex(a, len);

    int ansI = -1, ansJ = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            swap(a[i], a[j]);

            int current = getMex(a, len);

            if (current > best) {
                best = current;
                ansI = i + 1;
                ansJ = j + 1;
            }

            swap(a[i], a[j]);
        }
    }

    if (ansI == -1)
        cout << -1 << '\n';
    else
        cout << ansI << " " << ansJ << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}