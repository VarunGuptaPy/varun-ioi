#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
void printVec(vector<int> vec){
    for (int num: vec){
        cout << num << " ";
    }
}
void solve() {
    int n;
    cin >> n;
    list<int> people;

    for (int i = 1; i <= n; i++)

        people.push_back(i);

    auto it = people.begin();

    while (!people.empty()) {

        // move to every second person

        it++;

        if (it == people.end())

            it = people.begin();

        cout << *it << " ";

        // erase() returns iterator to next person

        it = people.erase(it);

        if (it == people.end())

            it = people.begin();

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