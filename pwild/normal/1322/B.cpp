#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

const ll K = 28;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	ll res = 0;
	FORD(k,0,K) {
		ll m = 1 << k;
		sort(all(a));
		
		auto sum = [&](ll i) {
			return lower_bound(all(a),i)-begin(a);
		};
		
		auto get = [&](ll i, ll j) {
			i %= 2*m, j %= 2*m;
			if (i < 0) i += 2*m;
			if (j < 0) j += 2*m;
			if (i < j) return sum(j)-sum(i);
			return n - (sum(i)-sum(j));
		};

		long long cur = 0;
		for (ll x: a) {
			cur += get(m-x,2*m-x);
			if ((x+x) & (1 << k)) cur--;
		}
		assert(cur%2 == 0);
		cur /= 2;
		if (cur%2) res |= 1 << k;
		
		for (ll &x: a) x %= m;
	}
	cout << res << endl;
}