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

	FOR(i,0,n) {
		if (a[i][0] == 'O' && a[i][1] == 'O') {
			a[i][0] = a[i][1] = '+';
			cout << "YES" << endl;
			FOR(i,0,n) cout << a[i] << endl;
			return 0;
		}
		if (a[i][4] == 'O' && a[i][3] == 'O') {
			a[i][4] = a[i][3] = '+';
			cout << "YES" << endl;
			FOR(i,0,n) cout << a[i] << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

}