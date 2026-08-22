#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    set<int> nArray;
    set<int> mArray;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        nArray.insert(num);
    }
    for (int i = 0; i<m;i++){
        int num;
        cin >> num;
        mArray.insert(num);
    }
    queue<int> conflictingNum;
    int leftN = k/2;
    int leftM = k/2;
    int processed = 0;
    for (int i = 1; i<=k; i++){
        bool presentM = mArray.count(i);
        bool presentN = nArray.count(i);
        if (presentM && presentN){
            conflictingNum.push(i);
        } else if (presentN && leftN >0){
            leftN--;
            processed++;
        } else if (presentM && leftM >0){

            leftM--;
            processed++;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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