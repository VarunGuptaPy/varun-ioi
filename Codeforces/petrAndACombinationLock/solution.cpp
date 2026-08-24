#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
int add(int current, int addedNum){
    if (current + addedNum > 360){
        return (current + addedNum) - 360;
    } else {
        return current + addedNum;
    }
}
int substract(int current,int substractedNum){
    if(current - substractedNum < 0){
        return 360 + (current - substractedNum);
    } else {
        return (current - substractedNum);
    }
}
bool possible(vector<int>& rotation, int n, int currentIndex, int currentValue){
    if (currentIndex == n && currentValue == 0) return true;
    if (currentIndex == n && currentValue != 0) return false;
    
    // add flow
    bool addition = possible(rotation,n,currentIndex+1,add(currentValue,rotation[currentIndex]));
    if (addition) return true;
    bool substration = possible(rotation,n,currentIndex+1,substract(currentValue,rotation[currentIndex]));
    return substration;
}
void solve() {
    int n;
    cin >> n;
    vector<int> rotation;
    for (int i = 0; i<n; i++){
        int rotate;
        cin >> rotate;
        rotation.push_back(rotate);
    }
    if (possible(rotation,n,0,0)){
        cout << "YES";
    } else {
        cout << "NO";
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