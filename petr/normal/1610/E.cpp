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

#define int64 int

class EAmShZAndGOAT {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
    }
    int res = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && a[j] == a[i]) ++j;

      int got = j - i;
      if (j < n) {
        int jump = a[j] - a[i];
        ++got;
        jump *= 2;
        while (a[n - 1] - a[i] >= jump) {
          int k = lower_bound(all(a), a[i] + jump) - a.begin();
          jump = a[k] - a[i];
          ++got;
          jump *= 2;
        }
      }
      res = max(res, got);

      i = j;
    }
    cout << n - res << "\n";
  }

  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    EAmShZAndGOAT solver;


    solver.solve();
    return 0;
}