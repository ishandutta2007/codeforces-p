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
// #include "../atcoder/all"

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

constexpr int64 INF = (int64) 1e18;

class DSlediZaBolshimSrednim {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int64> a(n);
    for (auto& x : a) cin >> x;
    int64 avg;
    cin >> avg;
    vector<int64> p(n + 1);
    for (int i = 0; i < n; ++i) {
      p[i + 1] = p[i] + a[i] - avg;
    }
    int res = 0;
    int64 sofar = -INF;
    int64 prev = 0;
    for (int i = 0; i < n; ++i) {
      if (p[i + 1] >= sofar) {
        ++res;
        sofar = max(sofar, prev);
        prev = p[i + 1];
      } else {
        sofar = -INF;
        prev = p[i + 1];
      }
    }
    cout << res << "\n";
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
    DSlediZaBolshimSrednim solver;


    solver.solve();
    return 0;
}