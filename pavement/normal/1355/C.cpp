#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int A, B, C, D, T, P[500005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> C >> D;
	for (int i = 1; i <= D; i++)
		P[i] = P[i - 1] + i;
	for (int z = C; z <= D; z++) {
		T += max(0ll, min(B, z - B + 1) - max(z - C + 1, A) + 1) * (C - z);
		if (min(B, z - B + 1) >= max(z - C + 1, A)) T += P[min(B, z - B + 1)] - P[max(z - C + 1, A) - 1];
		T += (C - B + 1) * max(0ll, B - max(A - 1, z - B + 1));
	}
	cout << T << '\n';
}