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

int out, ans, ans2;
vector<int> vec;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 100; i < (1 << 14); i++) {
		bool valid = 1;
		for (int j = 0; j < 7; j++)
			if (i & (1 << j)) valid = 0;
		if (valid) vec.pb(i);
	}
	assert(vec.size() >= 100);
	cout << "? ";
	for (int i = 0; i < 100; i++) cout << i << ' ';
	cout << endl;
	cin >> ans;
	cout << "? ";
	for (int i = 0; i < 100; i++) cout << vec[i] << ' ';
	cout << endl;
	cin >> ans2;
	for (int i = 7; i < 14; i++) out |= ans & (1 << i);
	for (int i = 0; i < 7; i++) out |= ans2 & (1 << i);
	cout << "! " << out << '\n';
}