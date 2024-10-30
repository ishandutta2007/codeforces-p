/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

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

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

constexpr int INF = (int) 1e9;

struct MaxFenwick {
  vector<int> a;

  explicit MaxFenwick(int n) : a(n, -1) {
  }

  void upd(int at, int val) {
    while (at < a.size()) {
      a[at] = max(a[at], val);
      at |= at + 1;
    }
  }

  int get(int upto) {
    int res = -1;
    while (upto >= 0) {
      res = max(res, a[upto]);
      upto = (upto & (upto + 1)) - 1;
    }
    return res;
  }
};

struct SumFenwick {
  vector<int> a;

  explicit SumFenwick(int n) : a(n, 0) {
  }

  void upd(int at, int val) {
    while (at < a.size()) {
      a[at] += val;
      at |= at + 1;
    }
  }

  int get(int upto) {
    int res = 0;
    while (upto >= 0) {
      res += a[upto];
      upto = (upto & (upto + 1)) - 1;
    }
    return res;
  }
};

class EGregorAndTheTwoPainters {
 public:
  vector<int> findTransfers(vector<int> x) {
    int n = x.size();
    int mx = 0;
    for (auto v : x) mx = max(mx, v);
    vector<int> res(n, INF);
    {
      MaxFenwick obstacles(n);
      MaxFenwick seen(mx + 1);
      for (int i = 0; i < n; ++i) {
        obstacles.upd(n - 1 - i, x[i]);
        int prev = seen.get(x[i]);
        if (prev >= 0) {
          int jump = obstacles.get(n - 1 - prev);
          res[i] = min(res[i], jump);
        }
        seen.upd(x[i], i);
      }
    }
    {
      MaxFenwick obstacles(n);
      MaxFenwick seen(mx + 1);
      for (int i = n - 1; i >= 0; --i) {
        obstacles.upd(i, x[i]);
        int prev = seen.get(x[i] - 1);
        if (prev >= 0) {
          int jump = obstacles.get(n - 1 - prev);
          res[i] = min(res[i], jump);
        }
        seen.upd(x[i], n - 1 - i);
      }
    }
    return res;
  }

  void solveOne() {
    int n, m, bound;
    cin >> n >> m >> bound;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    vector<int> b(m);
    for (auto& v : b) cin >> v;
    vector<int> x = findTransfers(a);
    vector<int> y = findTransfers(b);
    vector<ii> apairs;
    for (int i = 0; i < a.size(); ++i) {
      apairs.emplace_back(a[i], x[i]);
    }
    sort(all(apairs));
    reverse(all(apairs));
    vector<ii> bs;
    for (int i = 0; i < b.size(); ++i) {
      bs.emplace_back(b[i], i);
    }
    vector<ii> ys;
    for (int i = 0; i < y.size(); ++i) {
      ys.emplace_back(y[i], i);
    }
    sort(all(bs));
    sort(all(ys));
    int bptr = 0;
    int yptr = 0;
    vector<int> ok(b.size(), 1);
    int64 res = 0;
    SumFenwick sumFenwick(bound + 1);
    for (auto apair : apairs) {
      while (bptr < b.size() && bs[bptr].first + apair.first <= bound) {
        int i = bs[bptr++].second;
        ++ok[i];
        if (ok[i] == 2) {
          sumFenwick.upd(b[i], 1);
        }
      }
      while (yptr < b.size() && ys[yptr].first + apair.first <= bound) {
        int i = ys[yptr++].second;
        --ok[i];
        if (ok[i] == 1) {
          sumFenwick.upd(b[i], -1);
        }
      }
      res += sumFenwick.get(bound) - sumFenwick.get(bound - apair.second);
    }
/*    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i] + b[j] <= bound && a[i] + y[j] > bound && x[i] + b[j] > bound) {
          ++res;
        }
      }
    }*/
    cout << res << "\n";
  }

  void solve() {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    EGregorAndTheTwoPainters solver;


    solver.solve();
    return 0;
}