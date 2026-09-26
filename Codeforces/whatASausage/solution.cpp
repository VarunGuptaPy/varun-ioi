#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

vector<int> intersection(const vector<int>& a, const vector<int>& b) {
    vector<int> ans;

    for (int x : a) {
        for (int y : b) {
            if (x == y) {
                ans.push_back(x);
                break;
            }
        }
    }

    return ans;
}


int getAnswer(vector<int> arr,
              const vector<vector<int>>& todivisible) {

    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n - 1; i++) {

        // ai is already divisible
        if (arr[i] % 3 == 0) {
            cnt++;
            continue;
        }

        /*
            Find XOR values that can make BOTH
            arr[i] and arr[i+1] divisible by 3.
        */

        vector<int> inter =
            intersection(todivisible[arr[i]],
                         todivisible[arr[i + 1]]);

        if (!inter.empty()) {

            int x = inter[0];

            arr[i] ^= x;
            arr[i + 1] ^= x;

            // arr[i] is now divisible
            cnt++;
        }

        /*
            If no common XOR exists, arr[i]
            cannot be fixed using this edge
            with this greedy approach.
        */
    }

    // Last element was never counted in the loop
    if (arr[n - 1] % 3 == 0)
        cnt++;

    return cnt;
}


void solve(const vector<vector<int>>& todivisible) {

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];


    // Before any updates
    cout << getAnswer(arr, todivisible);

    while (q--) {

        int p, x;
        cin >> p >> x;

        --p;

        // update is permanent
        arr[p] = x;

        cout << " " << getAnswer(arr, todivisible);
    }

    cout << '\n';
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    vector<vector<int>> todivisible(16);

    for (int value = 0; value < 16; value++) {

        for (int k = 1; k <= 5; k++) {

            int x = 3 * k;

            if ((value ^ x) % 3 == 0) {
                todivisible[value].push_back(x);
            }
        }
    }


    int T;
    cin >> T;

    while (T--) {
        solve(todivisible);
    }

    return 0;
}