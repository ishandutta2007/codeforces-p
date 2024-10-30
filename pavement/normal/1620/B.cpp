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

int T, W, H, ans, k[5];
vector<int> vec[5];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> W >> H;
		for (int i = 0; i < 4; i++) {
			cin >> k[i];
			vec[i].clear();
			for (int j = 0, x; j < k[i]; j++) {
				cin >> x;
				vec[i].pb(x);
			}
		}
		for (int i = 0; i < 4; i++) {
			sort(vec[i].begin(), vec[i].end());
			ans = max(ans, (vec[i].back() - vec[i][0]) * (i <= 1 ? H : W));
		}
		cout << ans << '\n';
	}
}