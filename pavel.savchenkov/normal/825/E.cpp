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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"


int n, m;
vvi gr;
vi deg_out;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	gr.clear();
	gr.resize(n);
	deg_out.assign(n, 0);
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		gr[b].pb(a);
		++deg_out[a];
	}
	return 1;
}



void solve() {
	set<int> S;
	forn(i, n) {
		if  (deg_out[i] == 0) {
			S.insert(i);
		}
	}
	assert(!S.empty());

	vi lab(n, -1);
	int ptr = n - 1;
	while (!S.empty()) {
		int v = *S.rbegin();
		S.erase(v);

		lab[v] = ptr;
		--ptr;

		for (int to : gr[v]) {
			--deg_out[to];
			if  (!deg_out[to]) {
				S.insert(to);
			}
		}
	}

	forn(v, n) {
		printf("%d ", lab[v] + 1);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}