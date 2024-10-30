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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const ld EPS = 1e-9;
const int MAXN = 50 + 10;

char a[MAXN][MAXN];
int n, m;
int last[300];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &m);
  forn(i, n) gets(a[i]);

  int ans = 0;
  int timer = 0;
  forn(i, n - 1) forn(j, m - 1) {
    ++timer;    
    for (int ni = i; ni <= i + 1; ++ni) {
      for (int nj = j; nj <= j + 1; ++nj) {
        last[a[ni][nj] - 'a'] = timer;
      }
    }

    string f = "face";
    int cnt = 0;
    forn(i, sz(f)) {
      cnt += last[f[i] - 'a'] == timer;  
    }

    ans += cnt == 4;
  }

  cout << ans << endl;
  
  return 0;
}