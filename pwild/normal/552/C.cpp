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
	
	ll w, m; cin >> w >> m;

	if (w <= 3) {
		cout << "YES" << endl;
	} else {
		ll n = 0;
		vl p = {1};
		while (p[n] <= 1e10) p.pb(p[n++]*w);
		
		FORD(i,0,n) {
			if (m > p[i]) {
				m -= p[i];
			} else if (m == p[i]) {
				cout << "YES" << endl;
				return 0;
			} else if (m > p[i]/2) {
				m = p[i] - m;
			}
		}
		cout << "NO" << endl;
	}

}