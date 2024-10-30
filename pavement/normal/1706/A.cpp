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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, M, A[55], cnt[55];
char S[55];

main() {
	memset(S, 'B', sizeof S);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			if (A[i] > (M + 1) / 2) A[i] = M - A[i] + 1;
			cnt[A[i]]++;
		}
		for (int i = 1; i <= (M + 1) / 2; i++) {
			if (cnt[i] >= 2) S[i] = S[M - i + 1] = 'A';
			else if (cnt[i] == 1) S[i] = 'A';
		}
		for (int i = 1; i <= M; i++) {
			cout << S[i];
		}
		cout << '\n';
		for (int i = 1; i <= max(N, M); i++) {
			S[i] = 'B';
			cnt[i] = 0;
		}
	}
}