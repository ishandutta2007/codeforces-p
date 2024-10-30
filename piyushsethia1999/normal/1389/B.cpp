#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef print
#define print(...)
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
//const int mod = 998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int dp[6];
int a[100004];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int k; cin >> k;
		int z; cin >> z;
		memset(dp, 0, sizeof(dp));
		int ma = 0;
		for (int i = 0; i < n; ++i) cin >> a[i];
		dp[0] = a[0];
		for (int i = 1; i < n; ++i) {
			// print(pair(dp, ))
			for (int j = 0; j <= 5; ++j)
				dp[j] = dp[j] + a[i];
			for (int j = 1; j <= 5; ++j)
				dp[j] = max(dp[j], dp[j - 1] + a[i] + a[i - 1]);
			for (int j = 0; j <= 5; ++j) {
				if (i + 2 * j == k && j <= z)
					ma = max(ma, dp[j]);
				if (i + 2 * j + 1 == k && j + 1 <= z)
					ma = max(ma, dp[j] + a[i - 1]);
			}
		}
		cout << ma << '\n';
	}
}