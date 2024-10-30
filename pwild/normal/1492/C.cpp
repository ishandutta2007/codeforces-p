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
	
	ll m, n;
	cin >> m >> n;
	string s, t;
	cin >> s >> t;

	vl dpl(n), dpr(n);
	{
		ll j = 0;
		FOR(i,0,m) if (s[i] == t[j]) {
			dpl[j++] = i;
			if (j == n) break;
		}
	}
	{
		ll j = n-1;
		FORD(i,0,m) if (s[i] == t[j]) {
			dpr[j--] = i;
			if (j < 0) break;
		}
	}

	ll res = 0;
	FOR(i,0,n-1) res = max(res, dpr[i+1]-dpl[i]);
	cout << res << endl;
	
//	FOR(i,0,n) cout << dpl[i] << " \n"[i+1==n];
//	FOR(i,0,n) cout << dpr[i] << " \n"[i+1==n];
}