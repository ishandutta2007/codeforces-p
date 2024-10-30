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

class BFibonachchieviStroki {
 public:
  void solveOne() {
    int k;
    cin >> k;
    vector<int64> c(k);
    for (auto& x : c) cin >> x;
    int64 maxc = *max_element(all(c));
    vector<int64> f;
    f.push_back(1);
    f.push_back(1);
    while (true) {
      int64 v = f.back() + f[f.size() - 2];
      if (v > maxc) break;
      f.push_back(v);
    }
    for (int zero = 0; zero < c.size(); ++zero) {
      vector<bool> taken(f.size());
      taken[0] = true;
      bool ok = true;
      for (int i = 0; i < c.size() && ok; ++i) {
        int64 v = c[i];
        if (i == zero) --v;
        for (int j = f.size() - 1; j > 0; --j) {
          if (v >= f[j]) {
            if (taken[j] || (j == 1 && i == zero)) {
              ok = false;
              break;
            }
            taken[j] = true;
            v -= f[j];
            --j;
          }
        }
        if (ok) {
          assert(v == 0);
        }
      }
      for (int i = 0; i + 1 < f.size(); ++i) if (!taken[i] && taken[i + 1]) ok = false;
      if (ok) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
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
    BFibonachchieviStroki solver;


    solver.solve();
    return 0;
}