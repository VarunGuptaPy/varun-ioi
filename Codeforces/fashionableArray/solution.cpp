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
    vector<int> items;
    map<int,bool> added;
    map<int,int> count;
    
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        if (!added[num]){
            added[num] = true;
            items.push_back(num);
        }
        count[num]++;
    }
    sort(items.begin(),items.end(),greater<int>());
    int totalLeft = n;
    while (totalLeft != 0){
        for (int i = 0; i<items.size(); i++){
            cout << items[i] << ' ';
            count[items[i]]--;
            totalLeft--;
            if (count[items[i]] == 0){
                items.erase(items.begin() + i);
                i--;
            }
        }
    }
    cout << '\n';
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