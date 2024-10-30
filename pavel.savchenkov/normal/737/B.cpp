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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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

const int MAXN = 2e5 + 10;

int n, a, b, k;
char s[MAXN];

bool read() {
	if  (scanf("%d%d%d%d\n", &n, &a, &b, &k) < 4) {
		return 0;
	}
	gets(s);
	return 1;
}

int len(const pii& seg) {
	return seg.snd - seg.fst + 1;
}

void solve() {
	vi ans;
	set<pii> segs;
	for (int i = 0; i < n; ) {
		if  (s[i] == '1') {
			++i;
			continue;
		}
		int j = i;
		while (j < n && s[i] == s[j]) {
			++j;
		}
		segs.insert(mp(i, j - 1));
		i = j;
	}

	int sum = 0;
	for (const auto& seg : segs) {
		sum += len(seg) / b;
	}

	while (sum >= a) {
		auto seg = *segs.begin();
		segs.erase(seg);

		int l = seg.fst;
		int r = seg.snd;

		// printf("sum = %d, [%d, %d]\n", sum, l, r);

		if  (r - l + 1 < b) {
			continue;
		}

		sum -= len(seg) / b;

		ans.pb(l + b - 1);

		if  (l <= l + b - 2) {
			segs.insert(mp(l, l + b - 2));
		}
		if  (l + b <= r) {
			sum += (r - (l + b) + 1) / b;
			segs.insert(mp(l + b, r));
		}
	}

	printf("%d\n", sz(ans));
	for (int x : ans) {
		printf("%d ", x + 1);
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