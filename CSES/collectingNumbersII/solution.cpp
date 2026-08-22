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
    map<int,int> numIndex;
    map<int,int> indexNum;
    vector<int> numArray;
    for (int i = 1; i<=n; i++){
        int num;
        cin >> num;
        numIndex[num] = i;
        indexNum[i] = num;
        numArray.push_back(num);
    }
    vector<pii> swaps;
    for (int i = 0;i<m;i++){
        int first,second;
        cin >> first >> second;
        swaps.push_back({first,second});
       
    }
    int initialRounds = 1;
    for (int i = 1; i<n;i++){
        if (numIndex[i] > numIndex[i+1]){
            initialRounds++;
        }
        
    }
    for (pii swapi : swaps) {
    int numAtfirst = indexNum[swapi.first];
    int numAtSecond = indexNum[swapi.second];

    set<int> affected;

    if (numAtfirst > 1)
        affected.insert(numAtfirst - 1);
    if (numAtfirst < n)
        affected.insert(numAtfirst);

    if (numAtSecond > 1)
        affected.insert(numAtSecond - 1);
    if (numAtSecond < n)
        affected.insert(numAtSecond);

    // Remove old break-points
    for (int x : affected) {
        if (numIndex[x] > numIndex[x + 1])
            initialRounds--;
    }

    // Swap
    indexNum[swapi.first] = numAtSecond;
    numIndex[numAtSecond] = swapi.first;

    indexNum[swapi.second] = numAtfirst;
    numIndex[numAtfirst] = swapi.second;

    // Add new break-points
    for (int x : affected) {
        if (numIndex[x] > numIndex[x + 1])
            initialRounds++;
    }

    cout << initialRounds << '\n';
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