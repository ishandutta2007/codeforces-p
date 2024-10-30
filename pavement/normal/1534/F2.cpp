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

int N, M, ans, A[400005], v[400005], link[400005], sz[400005], mindp[400005], maxdp[400005];
char C[400005];
bool vis[400005];
vector<int> tmpvec, vec, adj[400005], scc[400005], rev[400005];

int cn, idx, rin[400005];
bitset<400005> inc;
stack<int> S;

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

inline int conv(int r, int c) {
	return (r - 1) * M + c;
}

void dfs(int n) {
	bool ro = 1;
	rin[n] = idx++;
	for (auto u : adj[n]) {
		if (rin[u] == -1) dfs(u);
		if (!inc[u] && rin[u] < rin[n])
			rin[n] = rin[u], ro = 0;
	}
	if (ro) {
		vector<int> v;
		inc[n] = 1;
		v.push_back(n);
		while (!S.empty() && rin[n] <= rin[S.top()]) {
			int w = S.top();
			S.pop();
			rin[w] = cn;
			inc[w] = 1;
			v.push_back(w);
		}
		rin[n] = cn;
		sort(v.begin(), v.end());
		for (int i : v)
			for (int j : adj[i])
				if (!binary_search(v.begin(), v.end(), j)) scc[rin[j]].pb(cn);
		cn++;
	} else S.push(n);
}
void get_scc() {
	memset(rin, -1, sizeof rin);
	inc.reset();
	for (int i = 1; i <= N * M; i++)
		if (C[i] == '#' && i == find(i) && rin[i] == -1) dfs(i);
}

void topo(int n) {
	if (vis[n]) return;
	vis[n] = 1;
	for (auto u : scc[n]) topo(u);
	vec.pb(n);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> C[conv(i, j)];
			link[conv(i, j)] = conv(i, j);
			sz[conv(i, j)] = 1;
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (i > 1 && C[conv(i, j)] == '#' && C[conv(i - 1, j)] == '#') unite(conv(i - 1, j), conv(i, j));
	for (int i = 1; i <= M; i++) cin >> A[i];
	for (int i = N; i >= 1; i--)
		for (int j = 1; j <= M; j++) {
			if (C[conv(i, j)] == '.' || conv(i, j) != find(conv(i, j))) continue;
			if (j > 1 && v[j - 1] && find(conv(i, j)) != find(conv(v[j - 1], j - 1))) adj[conv(i, j)].pb(find(conv(v[j - 1], j - 1)));
			if (j < M && v[j + 1] && find(conv(i, j)) != find(conv(v[j + 1], j + 1))) adj[conv(i, j)].pb(find(conv(v[j + 1], j + 1)));
			if (j > 1 && C[conv(i, j - 1)] == '#') adj[conv(i, j)].pb(find(conv(i, j - 1)));
			if (j < M && C[conv(i, j + 1)] == '#') adj[conv(i, j)].pb(find(conv(i, j + 1)));
			if (v[j] && find(conv(i, j)) != find(conv(v[j], j))) adj[conv(i, j)].pb(find(conv(v[j], j)));
			v[j] = i;
		}
	get_scc();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (C[conv(i, j)] != '#' || find(conv(i, j)) != conv(i, j)) continue;
			rev[rin[find(conv(i, j))]].pb(j);
		}
	}
	for (int i = 0; i < cn; i++) topo(i);
	for (int i : vec) {
		if (scc[i].empty()) {
			assert(!rev[i].empty());
			sort(rev[i].begin(), rev[i].end());
			mindp[i] = rev[i][0];
			maxdp[i] = rev[i].back();
		} else {
			mindp[i] = LLONG_MAX;
			maxdp[i] = LLONG_MIN;
			for (int j : scc[i]) {
				mindp[i] = min(mindp[i], mindp[j]);
				maxdp[i] = max(maxdp[i], maxdp[j]);
			}
			assert(mindp[i] != LLONG_MAX);
			assert(maxdp[i] != LLONG_MIN);
		}
	}
	vector<iii> events;
	for (int j = 1; j <= M; j++) {
		if (A[j] == 0) continue;
		int curr = 0;
		for (int i = N; i >= 1; i--) {
			if (C[conv(i, j)] == '#') {
				curr++;
				if (curr >= A[j]) {
					auto [x, y] = mp(mindp[rin[find(conv(i, j))]], maxdp[rin[find(conv(i, j))]]);
					events.eb(x, 0, j);
					events.eb(y, 1, j);
					break;
				}
			}
		}
	}
	set<int> yes;
	sort(events.begin(), events.end());
	for (auto [a, b, c] : events) {
		if (b) {
			if (yes.count(c)) ans++, yes.clear();
		} else {
			yes.insert(c);
		}
	}
	cout << ans << '\n';
}