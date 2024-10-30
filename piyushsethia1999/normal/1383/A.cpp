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

int a[24][24];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s, t; cin >> s >> t;
		memset(a, 0, sizeof(a));
		for (char& c : t) c -= 'a';
		for (char& c : s) c -= 'a';
		bool ok = 1;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				a[s[i]][t[i]] = 1;
				if (s[i] > t[i]) ok = 0; 
			}
		}
		if (!ok) {
			cout << "-1" << '\n';
			continue;
		} 
		int cn = 0;
		for (int i = 0; i < 20; ++i) {
			int j = i;
			while (!a[i][j] && j + 1 < 20) {
				j++;
			}
			if (a[i][j]) {
				cn++;
				for (int k = j + 1; k < 20; ++k) {
					a[j][k] += a[i][k];
				}
			}
		}
		cout << cn << '\n';
	}
}