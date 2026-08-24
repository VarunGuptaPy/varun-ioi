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

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {

        cin >> numbers[i];

    }

    sort(numbers.begin(), numbers.end());

    long long ans = 0;

    int start = 0;

    while (start < n) {

        int end = start + 1;

        while (end < n &&

               (numbers[start] & numbers[end]) >=

               (numbers[start] ^ numbers[end])) {

            end++;

        }

        long long count = end - start;

        ans += count * (count - 1) / 2;

        start = end;

    }

    cout << ans << '\n';

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