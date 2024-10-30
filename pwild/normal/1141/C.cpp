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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;

	vl d(n-1);
	FOR(i,0,n-1) cin >> d[i];
	
	vl a(n);
	FOR(i,0,n-1) a[i+1] = a[i]+d[i];
	
	ll sum = n*(n+1)/2 - accumulate(all(a),0LL);

	if (sum%n) {
		cout << -1 << endl;
		return 0;
	}
	
	FOR(i,0,n) a[i] += sum/n;
	
	FOR(i,0,n) if (a[i] < 1 || a[i] > n) {
		cout << -1 << endl;
		return 0;
	}
	
	vl b = a;
	sort(all(b));
	if (unique(all(b)) != end(b)) {
		cout << -1 << endl;
		return 0;
	}

	FOR(i,0,n) cout << a[i] << " ";
	cout << endl;

}