#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

long long countDivisor(long long start, long long end, long long num,long long oldCount, bool usePrev){
    long long count = 0;
    if (usePrev){
        count = oldCount;
    }
    for (long long i = start; i <= end; i++){
        if (num%i == 0){
            count ++;
        }
    }
    return count;
}

void solve() {
    long long num, k;
    cin >> num >> k;
    long long start = 1;
    long long end = num;
    long long mid = start + (end - start)/2;
    long long divisorCount = 0;
    bool usePrev = false;
    while ( end >= start){
        divisorCount = countDivisor(start,mid,num,divisorCount,usePrev);
        if (divisorCount == k){
            while (num % mid != 0){
                mid--;
            }
            cout << mid;
            return;
        } 
        if (divisorCount > k){
            end = mid -1;
            usePrev = true;
        } else {
            start = mid + 1;
            usePrev = false;
        }
        mid = start + (end - start)/2;
    }

    cout << "-1\n";
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