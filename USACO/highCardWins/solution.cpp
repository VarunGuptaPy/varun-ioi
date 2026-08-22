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
    vector<int> jessieCard;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        jessieCard.push_back(num);
    }
    set<int> bessieCard;
    int indexJessie = 0;
    for (int i = 1; i<= 2*n;i++){
        if (jessieCard[indexJessie] >i){
            bessieCard.insert(i);
        } else if (jessieCard[indexJessie] == i){
            indexJessie++;
        } else if (jessieCard[indexJessie] <i){
            bessieCard.insert(i);
        }
    }
    int won = 0;
    for (int i = 0; i<n;i++){
        auto itr = bessieCard.upper_bound(jessieCard[i]);
        if (itr == bessieCard.end()){
            bessieCard.erase(bessieCard.begin());
        } else {
            won++;
            bessieCard.erase(itr);
        }
    }
    cout << won;
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