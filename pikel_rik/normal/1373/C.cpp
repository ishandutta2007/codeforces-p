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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        ll res = 0;
        int mn = 0, cur = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '+')
                cur++;
            else cur--;
            if (cur < mn) {
                res += i + 1;
                mn = cur;
            }
        }

        res += n;
        cout << res << "\n";
    }
    return 0;
}