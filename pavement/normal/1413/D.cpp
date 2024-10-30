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

int N, v[200005], val[200005];
char c[200005];
vector<int> vec;
priority_queue<int, vector<int>, greater<int> > pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> c[i];
		if (c[i] == '+') {
			vec.pb(i);
		} else {
			cin >> v[i];
			if (vec.size() == 0) return cout << "NO\n", 0;
			val[vec.back()] = v[i];
			vec.ppb();
		}
	}
	for (int i = 1; i <= 2 * N; i++) {
		if (c[i] == '+') {
			pq.push(val[i]);
		} else {
			if (pq.top() != v[i]) return cout << "NO\n", 0;
			pq.pop();
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= 2 * N; i++)
		if (val[i]) cout << val[i] << ' ';
	cout << '\n';
}