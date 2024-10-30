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
using ordered_set = tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, A[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int chng = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 2; i < N; i++)
			if (A[i] > A[i - 1] && A[i] > A[i + 1]) A[i + 1] = (i + 2 <= N && A[i + 2] >= A[i] ? A[i + 2] : A[i]), chng++;
		cout << chng << '\n';
		for (int i = 1; i <= N; i++) cout << A[i] << ' ';
		cout << '\n';
	}
}