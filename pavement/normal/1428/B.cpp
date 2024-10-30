#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N;
char S[300005];
bool ret[300005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		bool t1 = 0, t2 = 0;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> S[i], ret[i] = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == '-') ret[i] = ret[(i + 1) % N] = 1;
			else if (S[i] == '<') t1 = 1;
			else t2 = 1;
		}
		int sum = 0;
		if (t1 && t2)
			for (int i = 0; i < N; i++) sum += ret[i];
		else sum = N;
		cout << sum << '\n';
	}
}