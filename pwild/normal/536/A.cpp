#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
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

	ll a, b, n; cin >> a >> b >> n;
	vi s(1e6+5);
	FOR(i,0,1e6+5) s[i] = a + i*b;

	FOR(i,0,n) {
		ll l, t, m; cin >> l >> t >> m;
		--l;
		
		ll mink = 0, maxk = 1e6+4-l;
		while (maxk-mink > 1) {
			ll k = (mink+maxk)/2;
			
			ll sum = k*(a + l*b) + b*k*(k-1)/2;
 			ll d = min(k,m);
			if (max((sum+d-1)/d,a+(l+k-1)*b) <= t) mink = k;
			else maxk = k;
		}
		
		if (mink) cout << l+mink << endl;
		else cout << -1 << endl;
	}


}