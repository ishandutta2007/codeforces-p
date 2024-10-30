#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 998244353;
int T, N, A[200005];

int exp_mod(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;	
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int ans = 0, cnt1 = 0, bad = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			if (A[i] == 1) cnt1++;
		}
		for (int i = N - cnt1 + 1; i <= N; i++) {
			if (A[i] == 0) bad++;
		}
		for (int i = 1; i <= bad; i++) {
			ans += exp_mod(i * i % MOD, MOD - 2);
			ans %= MOD;
		}
		ans *= (N * (N - 1) / 2) % MOD;
		ans %= MOD;
		cout << ans << '\n';
	}
}