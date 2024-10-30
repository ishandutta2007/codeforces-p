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

bool solve() {
	ll n, m;
	cin >> n >> m;
	
	ll ct = 0, clo = m, chi = m;

	bool res = true;
	while (n--) {
		ll t, lo, hi;
		cin >> t >> lo >> hi;
		
		ll dt = t-ct;
		clo -= dt, chi += dt;

		clo = max(clo, lo);
		chi = min(chi, hi);

		if (clo > chi) res = false;
		ct = t;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << (solve() ? "YES" : "NO") << endl;
}