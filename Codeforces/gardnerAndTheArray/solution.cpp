#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int,int> counts;
    vector<vector<int>> arr;
    for (int i = 0; i<n; i++){
        int count;
        cin >> count;
        vector<int> temp;
        for (int j = 0; j<count; j++){
            int num;
            cin >> num;
            temp.push_back(num);
            counts[num]++;
        }
        arr.push_back(temp);
    }
    string ans = "NO\n";
    for (int i = 0; i<n;i++){
        bool f = true;
        for(int num: arr[i]){
            if (counts[num] == 1){
                f = false;
                break;
            }
        }
        if (f == true){
            ans = "YES\n";
            break;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}