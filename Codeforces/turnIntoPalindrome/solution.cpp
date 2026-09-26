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
    char replaceChar;
    cin >> replaceChar;
    string theString;
    cin >> theString;
    int start = 0;
    int end = n-1;
    int count = 0;
    while (start <= end){
        char atStart = theString[start];
        char atEnd = theString[end];
        if (atStart == atEnd){
            start++;
            end--;
            
        } else if(atStart != replaceChar && atEnd == replaceChar){
            atStart = replaceChar;
            count++;
            start++;
            end--;
        } else if(atStart == replaceChar && atEnd != replaceChar){
            atEnd = replaceChar;
            count++;
            start++;
            end--;
        } else{
            atEnd = replaceChar;
            count++;
            atStart = replaceChar;
            count++;
            start++;
            end--;
        }
    }
    cout << count << '\n';
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