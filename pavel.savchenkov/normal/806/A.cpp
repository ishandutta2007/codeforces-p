#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"


ll x, y, p, q;

bool read() {
	if  (scanf("%lld%lld%lld%lld", &x, &y, &p, &q) < 4) {
		return 0;
	}
	return 1;
}



ll solve() {
	if  (p == q) {
		if  (x == y) {
			return 0;
		}
		return -1;
	}

	if  (!p) {
		if  (x == 0) {
			return 0;
		}
		return -1;
	}

	ll min_k = 0;
	assert(p);
	min_k = max(min_k, (x + p - 1) / p);
	assert(q);
	min_k = max(min_k, (y + q - 1) / q);

	ll nom = y - x;
	assert(nom >= 0);
	ll denom = q - p;
	assert(denom);
	min_k = max(min_k, (nom + denom - 1) / denom);

	return min_k * q - y;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (read()) {
		printf("%lld\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}