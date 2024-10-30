#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        int i;
        for (i = 0; a[i] == 1 and i < n; i++) {}

        if (i == n) {
            if (n % 2 == 0)
                cout << "Second\n";
            else cout << "First\n";
            continue;
        }

        if (i % 2 == 0)
            cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}