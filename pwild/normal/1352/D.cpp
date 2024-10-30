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
		FOR(i,0,n) cin >> a[i];

		ll i = 0, j = n-1;
		ll k = 0, suma = 0, sumb = 0, prv = 0;

		while (i <= j) {
			k++;
			ll cur = 0;

			while (i <= j && cur <= prv) {
				if (k%2) cur += a[i++];
				else cur += a[j--];
			}

			(k%2 ? suma : sumb) += cur;
			prv = cur;
		}
		cout << k << " " << suma << " " << sumb << endl;
	}
}