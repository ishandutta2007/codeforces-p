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
bool uda[1002];
int a[1002];

int main () {
    scanf("%d", &n);
    FORR(i, n) scanf("%d", &a[i]);

    int cnt = 0;
    int ans = 0;

    int now = 0;
    while (cnt < n) {
        ans++;
        now ^= 1;

        if (now) {
            FORR(i, n) if (!uda[i] && cnt >= a[i]) {
                cnt++;
                uda[i] = 1;
            }
        } else {
            for (int i=n-1; i>=0; i--) if (!uda[i] && cnt >= a[i]) {
                cnt++;
                uda[i] = 1;
            }
        }
    }

    return 0 * printf("%d\n", ans - 1);
}