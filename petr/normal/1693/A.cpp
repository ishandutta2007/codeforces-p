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

class ADirectionalIncrease {
 public:
  void solveOne() {
    int n;
    cin >> n;
    int64 s = 0;
    bool ok = true;
    bool hadZero = false;
    for (int i = 0; i < n; ++i) {
      int64 a;
      cin >> a;
      s += a;
      if (s < 0) ok = false;
      if (s == 0) hadZero = true;
      if (s > 0 && hadZero) ok = false;
    }
    if (s != 0) ok = false;
    if (ok) cout << "Yes"; else cout << "No";
    cout << "\n";
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
    ADirectionalIncrease solver;


    solver.solve();
    return 0;
}