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

class CGridXor {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto& x : a) for (auto& y : x) cin >> y;
    vector<vector<int>> b(n, vector<int>(n, 1));
    int res = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (b[i - 1][j]) {
          res ^= a[i][j];
          for (int ii = -1; ii <= 1; ++ii) {
            for (int jj = -1; jj <= 1; ++jj) {
              if (abs(ii) + abs(jj) == 1) {
                int ni = i + ii;
                int nj = j + jj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                  b[ni][nj] ^= 1;
                }
              }
            }
          }
        }
      }
    }
    for (int j = 0; j < n; ++j) assert(b[n - 1][j] == 0);
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
    CGridXor solver;


    solver.solve();
    return 0;
}