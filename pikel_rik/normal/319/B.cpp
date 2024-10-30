#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    stack<int> s;
    int ans = 0;

    dp[0] = inf;
    s.push(0);

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        while (!s.empty() and a[i] > a[s.top()]) {
            dp[i] = max(dp[i], dp[s.top()] + 1);
            s.pop();
        }
        s.push(i);
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] < inf)
            mx = max(mx, dp[i]);
    }

    cout << mx << "\n";
    return 0;
}