#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
deque<string> goSolve(string currentCow,map<string,vector<string>> &relations,set<string> &cowsLeft){
    deque<string> current;
    current.push_back(currentCow);
    vector<string> relation = relations[currentCow];
    cowsLeft.erase(currentCow);
    if(relation.size() == 0){
        return current;
    }
    for (int i = 0; i<relation.size();i++){
        if (cowsLeft.count(relation[i])){
            deque<string> gotBack = goSolve(relation[i],relations,cowsLeft);
            while(!gotBack.empty()){
                current.push_back(gotBack.front());
                gotBack.pop_front();
            }
        }
    }
    return current;
}
void solve() {
    vector<string> totalCows = {"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
    set<string> cowsLeft = {"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
    sort(totalCows.begin(),totalCows.end());
    int n;
    cin >> n;
    map<string,vector<string>> relation;
    for(int i = 0; i<n;i++){
        int total = 6;
        string first;
        string second;
        for (int j = 0; j<total; j++){
            string input;
            cin >> input;
            if (j == 0){
                first = input;
            }
            if (j == 5){
                second = input;
            }
        }
        relation[first].push_back(second);
        relation[second].push_back(first);
    }
    deque<string> finalOrder;
    for(string cow: totalCows){
        if (cowsLeft.count(cow)){
            if (relation[cow].size() == 2)
            continue;
            deque<string> currentCowOrder;
            currentCowOrder = goSolve(cow,relation,cowsLeft);
            while(!currentCowOrder.empty()){
                finalOrder.push_back(currentCowOrder.front());
                currentCowOrder.pop_front();
            }
        }
    }
    while(!finalOrder.empty()){
        cout << finalOrder.front() << '\n';
        finalOrder.pop_front();
    }
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}