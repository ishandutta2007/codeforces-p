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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const int A = 6;

int n, q;
int to[A][A];

bool read() {
  if  (scanf("%d%d\n", &n, &q) < 2) {
    return false;
  }
  memset (to, -1, sizeof to);
  forn(i, q) {
    char a, b, c;
    scanf("%c%c %c\n", &a, &b, &c);
    to[a - 'a'][b - 'a'] = c - 'a';
  }
  return true;
}

int s[10];
int ans;

bool ok() {
  int who = s[0];
  forn(i, n - 1) {
    int a = who;
    int b = s[i + 1];
    if  (to[a][b] == -1) return false;
    who = to[a][b];
  }
  return who == 0;
}

void go(int i) {
  if  (i == n) {
    if  (ok()) ++ans;
    return;
  }

  forn(c, A) {
    s[i] = c;
    go(i + 1);
  }
}

int solve() {
  ans = 0;
  go(0);
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    printf("%d\n", solve());
  }

#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}