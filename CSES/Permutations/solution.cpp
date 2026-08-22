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
    deque<int> dq;
    if (n == 1){
        cout << "1";
        return;
    }
    if (n<=3){
        cout << "NO SOLUTION";
        return;
    }
    if (n == 4){
        cout << "2 4 1 3" << endl;
        return ;
    }
    deque<int> front;
    deque<int> back;
    for (int i = 1; i<=n; i++){
        if (i % 2 == 0){
            front.push_front(i);
        } else {
            back.push_front(i);
        }
    }
    for(int i = 0; i<front.size(); i++){
            cout << front[i] << " ";
    }
    for(int i = 0; i<back.size(); i++){
            cout << back[i] << " ";
    }

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