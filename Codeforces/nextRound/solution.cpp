#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> places;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        places.push_back(num);
    }
    int kthPlace = places[k-1];
    int i = 0;
    int count = 0;
    while(i < places.size() && places[i] >= kthPlace && places[i] > 0){
        count++;
        i++;
    }
    cout << count;
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