#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    unsigned seed = chrono::steady_clock::now()
                        .time_since_epoch()
                        .count();

    if (argc >= 2) {
        seed = static_cast<unsigned>(stoul(argv[1]));
    }

    mt19937 rng(seed);

    auto random_int = [&](int left, int right) {
        return uniform_int_distribution<int>(left, right)(rng);
    };

    int n = random_int(1, 10);

    cout << n << '\n';

    for (int i = 0; i < n; ++i) {
        cout << random_int(-20, 20)
             << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}