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
    vector<int> songs;
    for (int i = 0; i<n; i++){
        int num;cin >> num;
        songs.push_back(num);
    }
    int mostSongs = 0;
    int start = 0;
    map<int,int> songsCount;
    for (int end = 0; end < n; end++){
        songsCount[songs[end]]++;
        while ( songsCount[songs[end]] > 1){
            songsCount[songs[start]]--;
            if (songsCount[songs[start]] == 0){
                songsCount.erase(songs[start]);
            }
            start++;
        }
        int size = end - start + 1;
        mostSongs = max(mostSongs,size);
    }
    cout << mostSongs;
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