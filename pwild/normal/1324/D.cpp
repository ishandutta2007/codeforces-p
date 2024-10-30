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
	
	ll n; cin >> n;
	
	vl a(n), b(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];

	vl v(n);
	FOR(i,0,n) v[i] = a[i]-b[i];
	sort(all(v));
	
	ll res = 0;
	FOR(i,0,n) {
		ll k = upper_bound(all(v),-v[i]) - begin(v);
		res += n-k;
		if (v[i] > 0) res--;
	}
	res /= 2;
	cout << res << endl;
}