#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int chance,a,b;
    cin >> chance >> a >> b;
    
    if ((a+b)>chance){
        cout << "NO\n";
        return;
    }
    if (min(a,b) == 0 && max(a,b) != 0){
        cout << "NO\n";
        return ;
    }
    vector<int> chances;
    for (int i = 1; i<=chance; i++){
        chances.push_back(i);
    }
    if (a == 0 && b == 0){
        cout << "YES\n";
        for (int num: chances){
            cout << num << ' ';
        }
        cout << '\n';
        for (int num: chances){
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    vector<int> chancesB;
    if ((a+b) ==  chance){
        for (int i = 0; i<b; i++){
            chancesB.push_back(chances[chance+i-b]);
        }
        for (int i = 0; i<a; i++){
            chancesB.push_back(chances[i]);
        }
    } else {
        int tie = abs(chance-(a+b));
        for (int i = 0; i<b; i++){
            chancesB.push_back(chances[chance+i-b-tie]);
        }
        for (int i = 0; i<a; i++){
            chancesB.push_back(chances[i]);
        }
        int start = chancesB.size();
        for (int i = start; i<(tie+start); i++){
            chancesB.push_back(chances[i]);
        }
    }
    cout << "YES\n";
    for (int i = 0; i<chances.size(); i++){
        cout << chances[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i<chancesB.size(); i++){
        cout << chancesB[i] << ' ';
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