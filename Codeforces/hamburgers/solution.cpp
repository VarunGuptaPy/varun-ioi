#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    vector<ll> initialQuantity;
    string burger;
    vector<ll> ingredientsPrice;
    ll amount;
    cin >> burger;
    for (int i = 0; i<3; i++){
        ll num; cin >> num; initialQuantity.push_back(num);
    }
    for (int i = 0; i<3; i++){
        ll num; cin >> num; ingredientsPrice.push_back(num);
    }
    cin >> amount;
    vector<ll> singlerBurgerAmount = {0,0,0};
    for (char s: burger){
        if (s == 'B'){
            singlerBurgerAmount[0]++;
        } else if (s == 'S'){
            singlerBurgerAmount[1]++;
        } else {
            singlerBurgerAmount[2]++;
        }
    }
    ll start = 0;
    ll end = 2000000000000LL;
    ll ans = 0;

    auto possible = [&](ll x) -> bool {
        ll buyRequiredBurger =
            max(0LL, x * singlerBurgerAmount[0] - initialQuantity[0]);

        ll buyRequiredSausage =
            max(0LL, x * singlerBurgerAmount[1] - initialQuantity[1]);

        ll buyRequiredCheese =
            max(0LL, x * singlerBurgerAmount[2] - initialQuantity[2]);

        ll totalPrice =
            ingredientsPrice[0] * buyRequiredBurger +
            ingredientsPrice[1] * buyRequiredSausage +
            ingredientsPrice[2] * buyRequiredCheese;

        return totalPrice <= amount;
    };

    while (start <= end) {
        ll mid = start + (end - start) / 2;

        if (possible(mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans;
    //  if (initialQuantity[0] < singlerBurgerAmount[0] && amount >= ingredientsPrice[0]){
    //     int diff = singlerBurgerAmount[0] - initialQuantity[0];
    //     initialQuantity[0] = singlerBurgerAmount[0];
    //     amount -= diff*ingredientsPrice[0];
    // } 
    // if (initialQuantity[1] < singlerBurgerAmount[1] && amount >= ingredientsPrice[1]){
    //     int diff = singlerBurgerAmount[1] - initialQuantity[1];
    //     initialQuantity[1] = singlerBurgerAmount[1];
    //     amount -= diff*ingredientsPrice[1];
    // } 
    // if (initialQuantity[2] < singlerBurgerAmount[2] && amount >= ingredientsPrice[2]){
    //     int diff = singlerBurgerAmount[2] - initialQuantity[2];
    //     initialQuantity[2] = singlerBurgerAmount[2];
    //     amount -= diff*ingredientsPrice[2];
    // }
    // while (initialQuantity[0] >= singlerBurgerAmount[0] && initialQuantity[1] >= singlerBurgerAmount[1] && initialQuantity[2] >= singlerBurgerAmount[2]){
    //     ans++;
    //     initialQuantity[0] -= singlerBurgerAmount[0];
    //     initialQuantity[1] -= singlerBurgerAmount[1];
    //     initialQuantity[2] -= singlerBurgerAmount[2];
    //     if (initialQuantity[0] < singlerBurgerAmount[0] && amount >= ingredientsPrice[0]){
    //         int diff = singlerBurgerAmount[0] - initialQuantity[0];
    //         initialQuantity[0] = singlerBurgerAmount[0];
    //         amount -= diff*ingredientsPrice[0];
    //     } 
    //     if (initialQuantity[1] < singlerBurgerAmount[1] && amount >= ingredientsPrice[1]){
    //         int diff = singlerBurgerAmount[1] - initialQuantity[1];
    //         initialQuantity[1] = singlerBurgerAmount[1];
    //         amount -= diff*ingredientsPrice[1];
    //     } 
    //     if (initialQuantity[2] < singlerBurgerAmount[2] && amount >= ingredientsPrice[2]){
    //         int diff = singlerBurgerAmount[2] - initialQuantity[2];
    //         initialQuantity[2] = singlerBurgerAmount[2];
    //         amount -= diff*ingredientsPrice[2];
    //     }
    // }
    // cout << ans << '\n';
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