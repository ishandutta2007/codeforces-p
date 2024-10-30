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
const int mod = 998244353;
// const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

const int N = 3004;

int dp[N];
int d1[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	string s; cin >> s;
	string t; cin >> t;
	int n = s.size();
	int m = t.size();
	int re = 0;
	for (int i = 0; i < m; ++i)
		if (s[0] == t[i])
			dp[i] = 1;
	dp[m] = 1;
	if (0 >= m - 1)
		re = (re + dp[0]) % mod;
	for (int i = 1; i < n; ++i) {	
		memset(d1, 0, sizeof(d1));
		for (int j = 0; j <= m; ++j) {
			if (j + i < m) {
				if (t[j + i] == s[i])
					d1[j] = (d1[j] + dp[j]) % mod;
			} else
				d1[j] = (d1[j] + dp[j]) % mod;
			if (j && t[j - 1] == s[i])
				d1[j - 1] = (d1[j - 1] + dp[j]) % mod;
		}
		d1[m] = (d1[m] + dp[m]);
		swap(d1, dp);
		if (i >= m - 1)
			re = (re + dp[0]) % mod;
	}
	cout << (re * 2) % mod << "\n";
}