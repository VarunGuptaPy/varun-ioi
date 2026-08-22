#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    deque<int> cards;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        int num;
        cin >> num;
        cards.push_back(num);
    }
    int sareja = 0;
    int dima = 0;
    int count = 0;
    while(!cards.empty()){
        if (count%2==0){
            //sareja turn
            int front = cards.front();
            int back = cards.back();
            if(front > back){
                sareja+= front;
                cards.pop_front();
            } else {
                sareja+= back;
                cards.pop_back();
            }
        }else {
            //dima turn
            int front = cards.front();
            int back = cards.back();
            if(front > back){
                dima+= front;
                cards.pop_front();
            } else {
                dima+= back;
                cards.pop_back();
            }
        }
        count++;
    }
    cout << sareja << " " << dima;
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