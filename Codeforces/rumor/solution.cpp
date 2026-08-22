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
    vector<int> bribe;
    for (int i = 0;i<n;i++){
        int num;
        cin >> num;
        bribe.push_back(num);
    }
    map<int,deque<int>> freinds;
    for (int i = 0; i<m; i++){
        int first,second;
        cin >> first >> second;
        freinds[second].push_back(first);
        freinds[first].push_back(second);
    }
    map<int,bool> done;
    ll ans = 0;
    for (int i = 1; i<=n;i++){
        if (!done[i]){
            deque<int> curr;
            int minPrice = bribe[i-1];
            curr.push_back(i);
            while(!curr.empty()){
                int front = curr.front();
                minPrice = min(minPrice,bribe[front-1]);
                if (!done[front]){
                    curr.insert(curr.end(),freinds[front].begin(),freinds[front].end());
                    done[front] = true;
                }
                curr.pop_front();
            }
            ans += minPrice;
        }
    }
    cout << ans;
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