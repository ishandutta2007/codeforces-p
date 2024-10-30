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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, ans = LLONG_MAX, A[100005], P[100005];

int bb(int x) {
	return __builtin_clzll(x);
}

int rxor(int l, int r) {
	return P[r] ^ P[l - 1];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i], P[i] = P[i - 1] ^ A[i];
	for (int i = 3; i <= N; i++) {
		if (bb(A[i]) == bb(A[i - 1]) && bb(A[i - 1]) == bb(A[i - 2])) return cout << "1\n", 0;
	}
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
			for (int k = j + 1; k <= N; k++)
				if (rxor(i, j) > rxor(j + 1, k)) ans = min(ans, k - (j + 1) + j - i);
	cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}