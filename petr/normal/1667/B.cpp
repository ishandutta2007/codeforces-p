/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

#undef NDEBUG

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
// AtCoder library from https://github.com/atcoder/ac-library

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

constexpr int64 INF = (int64) 1e18;

// Modified from atcoder library
struct fenwick_tree {
  using U = int64;
  using T = int64;

 public:
  fenwick_tree() : _n(0) {}
  fenwick_tree(int n) : _n(n), data(n, -INF) {}

  void upd(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while (p <= _n) {
      data[p - 1] = max(data[p - 1], U(x));
      p += p & -p;
    }
  }

  U getmax(int r) {
    U s = -INF;
    while (r > 0) {
      s = max(s, data[r - 1]);
      r -= r & -r;
    }
    return s;
  }

 private:
  int _n;
  std::vector<U> data;

};


class BOptimalnoeRazbienie {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int64> a(n);
    for (auto& x : a) cin >> x;
    vector<int64> p(n + 1);
    for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];
    vector<int64> up = p;
    sort(all(up));
    up.erase(unique(all(up)), up.end());
    for (int i = 0; i <= n; ++i) p[i] = lower_bound(all(up), p[i]) - up.begin();

    vector<int64> bestEq(up.size(), -INF);
    fenwick_tree bestInc(up.size());
    int64 bestDec;

    bestEq[p[0]] = 0;
    bestInc.upd(p[0], 0);
    bestDec = 0;
    for (int i = 1; i <= n; ++i) {
      int64 best = bestDec - i;
      best = max(best, bestEq[p[i]]);
      best = max(best, bestInc.getmax(p[i]) + i);
      if (i == n) {
        cout << best << "\n";
      }
      bestEq[p[i]] = max(bestEq[p[i]], best);
      bestInc.upd(p[i], best - i);
      bestDec = max(bestDec, best + i);
    }
  }

  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      // cout << "Case #" << (it + 1) << ": ";
      solveOne();
    }
  }
};

// #define st_mtimespec st_mtim

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    BOptimalnoeRazbienie solver;


    solver.solve();
    return 0;
}