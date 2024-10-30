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

int T, N, M;
char C[55][55];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) cin >> C[i][j];
		for (int j = 1; j <= M; j++) C[N + 1][j] = 'o';
		N++;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (C[i][j] == 'o') {
					int cnt = 0;
					for (int k = i - 1; k >= 1; k--)
						if (C[k][j] == 'o') break;
						else if (C[k][j] == '*') C[k][j] = '.', cnt++;
					for (int k = i - 1; k >= i - cnt; k--)
						C[k][j] = '*';
				}
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 1; j <= M; j++) cout << C[i][j];
			cout << '\n';
		}
	}
}