#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Lab {
    ll a, b, c;
    ll sum;

    // 0 = can increase immediately
    // 1 = requires setup
    // 2 = frozen
    int type;

    ll setup;
};

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<Lab> labs(n);

    ll initialMin = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll sum = a + b + c;

        labs[i].a = a;
        labs[i].b = b;
        labs[i].c = c;
        labs[i].sum = sum;

        initialMin = min(initialMin, sum);

        // Completely frozen
        if (a == b && b == c) {
            labs[i].type = 2;
            labs[i].setup = 0;
        }

        // Already has some inversion:
        //
        // b > c  -> increase a
        // a > c  -> increase b
        // a > b  -> increase c
        else if (b > c || a > c || a > b) {
            labs[i].type = 0;
            labs[i].setup = 0;
        }

        // Here necessarily a <= b <= c
        else {
            labs[i].type = 1;

            ll setup = LLONG_MAX;

            /*
                Option 1:

                decrease b until b < a

                b -> a - 1

                operations = b - a + 1

                This operation is possible while a < c because

                b += sgn(a - c)
            */
            if (a < c) {
                setup = min(setup, b - a + 1);
            }

            /*
                Option 2:

                decrease c until c < b

                c -> b - 1

                operations = c - b + 1

                Possible while a < b because

                c += sgn(a - b)
            */
            if (a < b) {
                setup = min(setup, c - b + 1);
            }

            labs[i].setup = setup;
        }
    }

    auto can = [&](ll target) -> bool {
    ll operations = 0;

    for (const Lab &lab : labs) {

        if (lab.sum >= target)
            continue;

        ll need = target - lab.sum;

        // Frozen lab
        if (lab.type == 2)
            return false;

        ll cost;

        if (lab.type == 0) {
            cost = need;
        }
        else {
            // Avoid overflow
            if (lab.setup > k)
                return false;

            if (need > k - 2 * lab.setup)
                return false;

            cost = need + 2 * lab.setup;
        }

        if (operations > k - cost)
            return false;

        operations += cost;
    }

    return operations <= k;
};
    /*
        Answer can never exceed initialMin + k,
        because each operation changes a laboratory's
        sum by at most +1.
    */

    ll lo = initialMin;
    ll hi = initialMin + k + 1; // impossible/exclusive

    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;

        if (can(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}