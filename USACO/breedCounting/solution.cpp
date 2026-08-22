#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n,q;
    cin >> n >> q;
    int first[n];
    int second[n];
    int third[n];
    int countFirst = 0;
    int countSecond = 0;
    int countThird = 0;
    for (int i = 0; i<n;i++){
        int num;
        cin>>num;
        switch (num){
            case 1:
                countFirst++;
                break;
            case 2:
                countSecond++;
                break;
            case 3:
                countThird++;
                break;
            default:
                break;
        }
        first[i] = countFirst;
        second[i] = countSecond;
        third[i] = countThird;
    }
    for (int i = 0; i<q; i++){
        int start,end;
        int firstCount;
        int secondCount;
        int thirdCount;
        cin >> start >> end;
        end--;
        if (start == 1){
            firstCount = first[end];
            secondCount = second[end];
            thirdCount = third[end];
        } else {
            start-=2;
            firstCount = first[end] - first[start];
            secondCount = second[end] - second[start];
            thirdCount = third[end] - third[start];
        }
        cout << firstCount << ' ' << secondCount << ' ' << thirdCount << '\n';
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