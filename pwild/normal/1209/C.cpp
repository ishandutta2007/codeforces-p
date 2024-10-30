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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vl a(n);
		FOR(i,0,n) {
			char c; cin >> c;
			a[i] = c-'0';
		}

		bool found = false;
		FOR(k,0,10) {
			string res(n,' ');
			ll x = 0, y = k;
			bool ok = true;
			FOR(i,0,n) {
				if (a[i] < x) {
					ok = false;
				} else if (a[i] < y) {
					x = a[i];
					res[i] = '1';
				} else {
					y = a[i];
					res[i] = '2';
				}
			}
			if (x > k) ok = false;
			if (ok) {
				found = true;
				cout << res << endl;
				break;
			}
		}
		if (!found) cout << "-" << endl;
	}
}