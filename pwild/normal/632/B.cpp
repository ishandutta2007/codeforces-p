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
	vl p(n);
	FOR(i,0,n) cin >> p[i];
	string s;
	cin >> s;

	ll sum = 0;
	FOR(i,0,n) if (s[i] == 'B') sum += p[i];
	
	ll res = sum;
	FOR(dir,0,2) {
		ll cur = 0;
		FOR(i,0,n) {
			if (s[i] == 'A') cur += p[i]; else cur -= p[i];
			res = max(res,sum+cur);
		}
		reverse(all(p)), reverse(all(s));
	}
	cout << res << endl;

}