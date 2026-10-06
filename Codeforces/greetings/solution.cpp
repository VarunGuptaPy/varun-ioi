#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

long long mergeCount(vector<int>& a, int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;

    long long ans = 0;
    ans += mergeCount(a, l, mid);
    ans += mergeCount(a, mid + 1, r);

    vector<int> temp;

    int i = l;
    int j = mid + 1;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            // a[i] > a[j]
            // so every element from i...mid is also > a[j]
            ans += (mid - i + 1);

            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(a[i++]);
    }

    while (j <= r) {
        temp.push_back(a[j++]);
    }

    for (int k = 0; k < temp.size(); k++) {
        a[l + k] = temp[k];
    }

    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<pii> startEnd(n);
    for (int i = 0; i<n; i++){
        cin >> startEnd[i].first >> startEnd[i].second;
    }
    sort(startEnd.begin(),startEnd.end());
    vector<int> ends(n);
    for (int i = 0; i<n; i++){
        ends[i] = startEnd[i].second;
    }
    cout << mergeCount(ends,0,n-1) << '\n';
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