#include <list>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll MOD = 1000000007;

ll p[505];
ll dp[505][505];
ll dp2[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	
	ll n; cin >> n;
	FOR(i,0,n) cin >> p[i];

	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));

	FOR(len,0,n) {
		FOR(a,0,n) {
			ll b = a+len;
			if (a == b) {
				dp[a][b] = dp2[a][b] = 1;
				continue;
			}
			dp[a][b] += dp2[a+1][b];
			dp2[a][b] = dp[a][b];
			FOR(c,a,b) {
				if (p[c+1] > p[a]) dp2[a][b] = (dp2[a][b] + dp[a][c]*dp2[c+1][b]) % MOD;
			}

		}
	}
	cout << dp[0][n-1] << endl;

}