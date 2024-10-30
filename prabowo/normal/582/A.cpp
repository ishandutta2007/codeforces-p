#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <istream>
#include <ostream>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define MOD9 1000000009
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORR(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define UNIK(x) unique(ALL(x) - x.begin())
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SYNC ios_base::sync_with_stdio(0)
#define kita using
#define emang namespace
#define ganteng std

kita emang ganteng;

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> pipii;

typedef vector <int> vi;
typedef vector <pii> vii;
typedef pair <LL, LL> pll;
typedef vector <LL> vl;
typedef vector <pll> vll;

//////// End of Template ////////

int n;
multiset <int> gcd;
vi ans;
int a;

int fpb(int x, int y) {
    return y ? fpb(y, x % y) : x;
}

int main () {
    scanf("%d", &n);
    FORR(i, n*n) {
        scanf("%d", &a);
        gcd.insert(a);
    }

    FORR(i, n) {
        int tmp = *gcd.rbegin();
        FORR(j, ans.size()) {
            int tmp2 = fpb(tmp, ans[j]);
            FORR(k, 2) gcd.erase(gcd.find(tmp2));
        }

        gcd.erase(gcd.find(tmp));
        ans.pb(tmp);
    }

    FORR(i, n) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}