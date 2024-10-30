#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

int n;
int a[MN], b[MN];
vector<int> G[MN];

void Solve();

int main() {
	int tests = 1;
//	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i), b[a[i]] = i;
	int ans = n;
	for (int i = 1; i <= n; ++i) {
		if (b[a[i]] == i) {
			--ans;
			continue;
		}
		int p = i, k = b[a[i]], c = 1;
		while (true) {
			int m = k;
			F(j, p + 1, k - 1)
				m = max(m, b[a[j]]);
			if (m > k)
				p = k, k = m, ++c;
			else
				break;
		}
		ans -= c + 1;
		i = k;
	}
	printf("%d\n", ans);
}