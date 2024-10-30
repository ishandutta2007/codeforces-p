#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}
long long md(long long x, long long mod) {
	return ((x % mod) + mod) % mod;
}
long long add(long long x, long long y, long long mod) {
	return md(md(x, mod) + md(y, mod), mod);
}
long long sub(long long x, long long y, long long mod) {
	return md(md(x, mod) - md(y, mod), mod);
}
long long mul(long long x, long long y, long long mod) {
	return md(md(x, mod) * md(y, mod), mod);
}
void solve() {
	int n, k; cin >> n >> k;
	vector <int> a(n), w(k);
	for (auto& x : a) cin >> x;
	for (auto& x : w) cin >> x;
	vector <vector <int>> ppl(k);
	sort(a.rbegin(), a.rend());
	sort(w.begin(), w.end());
	for (int i = 0; i < k; ++i) {
		ppl[i].push_back(a[i]);
	}
	int curi = 0;
	for (int i = k; i < n; ++i) {
		while (ppl[curi].size() == w[curi]) curi++;
		ppl[curi].push_back(a[i]);
	}
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += ppl[i][0] + ppl[i][w[i] - 1];
	}
	cout << ans << endl;

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}