#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,w;
    cin >> n >> w;
    multiset<int> rectangleWidth;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        rectangleWidth.insert(num);
    }
    int height = 1;
    int currW = 0;
    while(!rectangleWidth.empty()){
        if (currW == 0){
            auto it = prev(rectangleWidth.end());
            currW = *(it);
            rectangleWidth.erase(it);
        } else if (currW < w) {
            auto it = rectangleWidth.upper_bound(w - currW);
            if (it != rectangleWidth.begin()){
                --it;
                currW += *(it);
                rectangleWidth.erase(it);
            } else {
                height++;
                currW = 0;
            }
        } else {
            height++;
            currW = 0;
        }
    }
    cout << height << '\n';
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