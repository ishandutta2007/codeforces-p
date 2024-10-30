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
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	for (auto x : a) {
		int f = ceil(sqrt(x));
		//debug(f);
		if (f * f != x or f == 1) cout << "NO\n";
		else {
			int i = 2; bool c = true;
			while (i * i <= f) {
				//debug(i);
				if (f % i == 0) {
					c = false; break;
				}
				++i;
			}
			if (c)cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; t = 1;
	while (t--) {
		solve();
	}
	return 0;
}