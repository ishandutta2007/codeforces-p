#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

struct dsu {
	ll n;
	vl p;

	dsu(ll n): n(n), p(n) { iota(all(p),0); }
	
	ll find(ll x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}

	bool unite(ll x, ll y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		
		if (rand() & 1) swap(x,y);
		p[y] = x;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vvl A(n, vl(n));
	FOR(i,0,n) FOR(j,0,n) cin >> A[i][j];

	vector<pll> edges;
	vl c(n);
	FOR(i,0,n) c[i] = A[i][i];

	function<ll(vl)> rec = [&](vl v) {
		if (sz(v) == 1) return v[0];

		dsu D(sz(v));

		ll x = 0;
		for (ll a: v) x = max(x, A[v[0]][a]);

		FOR(i,0,sz(v)) FOR(j,0,sz(v)) {
			ll a = v[i], b = v[j];
			if (A[a][b] < x) D.unite(i,j);
		}
		
		vvl comps(sz(v));
		FOR(i,0,sz(v)) comps[D.find(i)].pb(v[i]);
		
		ll r = n++;
		c.pb(x);

		for (vl w: comps) if (sz(w)) {
			edges.eb(rec(w),r);
		}
		
		return r;
	};

	vl v(n);
	iota(all(v),0);
	ll r = rec(v);
	
	cout << n << endl;
	FOR(i,0,n) cout << c[i] << " \n"[i+1==n];
	cout << r+1 << endl;
	for (auto [a,b]: edges) cout << a+1 << " " << b+1 << endl;
}