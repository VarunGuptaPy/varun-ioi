#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void goSolve(double &correct, double &total, int currPos, int requiredPos, int questionMarkLeft){
    if (questionMarkLeft == 0 && currPos == requiredPos){
        correct++;
        total++;
        return;
    }
    if (questionMarkLeft == 0 && currPos != requiredPos){
        total++;
        return;
    }
    goSolve(correct,total,currPos+1,requiredPos,questionMarkLeft-1);
    goSolve(correct,total,currPos-1,requiredPos,questionMarkLeft-1);
}
void solve() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int firstPosition = 0;
    for (char s: s1){
        if (s == '+'){
            firstPosition++;
        } else {
            firstPosition--;
        }
    }
    int questMarkCount = 0;
    int secondPos = 0;
    for (char s: s2){
        if (s == '?'){
            questMarkCount++;
        } else if (s == '+'){
            secondPos++;
        } else {
            secondPos--;
        }
    }
    double correct = 0;
    double total = 0;
    goSolve(correct,total,secondPos,firstPosition,questMarkCount);
    cout << fixed << setprecision(12) << correct / total << '\n';
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