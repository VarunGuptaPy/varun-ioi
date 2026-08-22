#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

vector<int> merge(vector<int> vec1, vector<int>vec2){
    int first = 0;
    int second = 0;
    int size1 = vec1.size();
    int size2 = vec2.size();
    vector<int> ans;
    while (first < size1 && second < size2){
        if (vec1[first] > vec2[second]){
            ans.push_back(vec2[second]);
            second++;
        } else if (vec1[first] < vec2[second]){
            ans.push_back(vec1[first]);
            first++;
        } else {
            ans.push_back(vec2[second]);
            second++;
            ans.push_back(vec1[first]);
            first++;
        }
    }
    while (first < size1){
        ans.push_back(vec1[first]);
        first++;
    }
    while(second < size2){
        ans.push_back(vec2[second]);
        second++;
    }
    return ans;
}
vector<int> mergeSort(vector<int> vec, int start, int end){
    if(end-start == 0){
        return {vec[start]};
    }
    int mid = (start+end)/2;
    vector<int> vec1 = mergeSort(vec,start,mid);
    vector<int> vec2 = mergeSort(vec,mid+1,end);
    return merge(vec1,vec2);
}
void solve() {
    int n;
    cin >> n;
    vector<int> blocks;
    for (int i =0; i< n; i++){
        int num;
        cin >> num;
        blocks.push_back(num);
    }
    blocks = mergeSort(blocks,0,blocks.size()-1);
    for (int a: blocks){
        cout << a << " ";
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