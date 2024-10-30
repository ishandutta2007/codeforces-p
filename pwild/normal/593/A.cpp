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
	
	ll n; cin >> n;
	vector<string> a(n);
	FOR(i,0,n) cin >> a[i];
	
	vector<set<ll>> v(n);
	FOR(i,0,n) FOR(j,0,sz(a[i])) v[i].insert(a[i][j]-'a');

	ll res = 0;
	FOR(i,0,26) FOR(j,i+1,26) {
		ll cur = 0;
		FOR(t,0,n) {
			bool ok = true;
			for (auto k: v[t]) if (k != i && k != j) ok = false;
			if (ok) cur += sz(a[t]);
		}
		res = max(res,cur);
	}
	cout << res << endl;


}