#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Item {
    ll amount;
    int type;
    ll id;
};

vector<Item> q;
ll added = 0;

void solve() {
    int op;
    cin >> op;

    if (op == 1) {
        ll S;
        int type;
        cin >> S >> type;

        ++added;
        q.push_back({S, type, added});
    }

    else if (op == 2) {
        ll id;
        cin >> id;

        // IDs correspond to insertion indices because we NEVER erase.
        q[id - 1].amount = 0;
    }

    else if (op == 3) {
        ll need;
        cin >> need;

        map<ll, ll> removed;

        for (ll i = 0; i < (ll)q.size() && need > 0; ++i) {

            // Already deleted/empty
            if (q[i].amount == 0)
                continue;

            // type 0:
            // take it only if the whole amount fits
            if (q[i].type == 0) {

                if (q[i].amount <= need) {
                    need -= q[i].amount;
                    removed[q[i].id] += q[i].amount;

                    q[i].amount = 0;
                }
            }

            // type 1:
            // partial removal is allowed
            else {

                ll take = min(q[i].amount, need);

                q[i].amount -= take;
                need -= take;

                removed[q[i].id] += take;
            }
        }

        cout << removed.size() << '\n';

        for (auto &[id, amount] : removed) {
            cout << id << " " << amount << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q--) {
        solve();
    }
}