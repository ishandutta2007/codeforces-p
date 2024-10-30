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

class CMenora {
 public:
  void solveOne() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int n01 = 0;
    int n10 = 0;
    int n11 = 0;
    int n00 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == '0' && b[i] == '0') ++n00;
      if (a[i] == '0' && b[i] == '1') ++n01;
      if (a[i] == '1' && b[i] == '0') ++n10;
      if (a[i] == '1' && b[i] == '1') ++n11;
    }
    if (n01 == 0 && n10 == 0) {
      cout << 0 << "\n";
      return;
    }
    if (n10 == 0 && n11 == 0) {
      cout << -1 << "\n";
      return;
    }
    if (n01 == 0 && n11 == 0) {
      cout << -1 << "\n";
      return;
    }
    int res = (int) 1e9;
    if (n01 == n10) {
      int cur = max(n01, n10) * 2;
      res = min(res, cur);
    }
    if (n11 == n00 + 1) {
      res = min(res, max(n11, n00 + 1) * 2 - 1);
    }
    if (res == (int) 1e9)
      res = -1;
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
    CMenora solver;


    solver.solve();
    return 0;
}