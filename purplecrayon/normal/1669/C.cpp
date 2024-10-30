#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    for (int i = 2; i < n; i++) {
        if (a[i] % 2 != a[i-2] % 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}