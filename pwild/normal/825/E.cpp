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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;

	vl indeg(n);
	vvl adj(n);
	while (m--) {
		ll a, b; cin >> a >> b;
		a--, b--;
		adj[b].pb(a);
		indeg[a]++;
	}
	
	set<ll> q;
	FOR(i,0,n) if (!indeg[i]) q.insert(-i);
	
	vl res;
	while (sz(q)) {
		ll i = -(*begin(q));
		q.erase(begin(q));
		res.pb(i);
		for (ll j: adj[i]) if (--indeg[j] == 0) q.insert(-j);
	}
	
	reverse(all(res));

	vl resi(n);
	FOR(i,0,n) resi[res[i]] = i;

	FOR(i,0,n) cout << resi[i]+1 << " \n"[i+1==n];
}