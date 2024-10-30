//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
	~__timestamper(){
        TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;


int main() {
#ifdef LOCAL
  assert(freopen(TASKNAME".in", "r", stdin));
  assert(freopen(TASKNAME".out", "w", stdout));
#endif

  int n;
  scanf("%d",&n);
  vector<long long> v(n);

  long long need = 0;

  for (int i = 0; i < n; i++) {
    long long a, b;
    scanf("%lld %lld\n", &a, &b);
    need ^= a;
    v[i] = a ^ b;
  }

  v.push_back(need);

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    if (v[i] == 0) continue;
    cnt++;
    long long bit = v[i] &~(v[i] - 1);
    for (int j = i + 1; j <= n; j++) {
      if (v[j] & bit) {
        v[j] ^= v[i];
      }
    }
  }

  if (v[n] == 0) {
    printf("%lld/%lld\n", (1LL << cnt) - 1, (1LL << cnt));
  } else {
    printf("1/1\n");
  }
  return 0;
}