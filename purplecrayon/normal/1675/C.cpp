#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    int o = 0;
    for (int i = 0; i < n; i++) if (s[i] == '1') o++;
    int ans = 0, z = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') o--;
        ans += !z && !o;
        if (s[i] == '0') z++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}