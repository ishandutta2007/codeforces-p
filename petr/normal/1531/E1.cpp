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
//#include "../atcoder/all"

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

class E3SortirovkaSliyaniem {
 public:
  int n;
  string log;
  int logPtr;
  vector<int> a, b;

  bool mergeSort(int l, int r) {
    if (r - l <= 1) {
      return true;
    }
    int m = (l + r) >> 1;
    if (!mergeSort(l, m)) return false;
    if (!mergeSort(m, r)) return false;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
      if (logPtr >= log.size()) return false;
      if (log[logPtr++] == '0') {
        b[k] = a[i];
        i += 1;
      } else {
        b[k] = a[j];
        j += 1;
      }
      k += 1;
    }
    while (i < m) {
      b[k] = a[i];
      i += 1;
      k += 1;
    }
    while (j < r) {
      b[k] = a[j];
      j += 1;
      k += 1;
    }
    for (int p = l; p < r; ++p) {
      a[p] = b[p];
    }
    return true;
  }


  void solveOne() {
    cin >> log;
    for (n = 1;; ++n) {
      a.resize(n);
      b.resize(n);
      for (int i = 0; i < n; ++i) a[i] = i;
      logPtr = 0;
      if (mergeSort(0, n)) {
        if (logPtr == log.size()) {
          cout << n << "\n";
          vector<int> src(n);
          for (int i = 0; i < n; ++i) src[a[i]] = i + 1;
          for (int x : src) cout << x << " ";
          cout << "\n";
          return;
        }
      }
    }
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
    E3SortirovkaSliyaniem solver;


    solver.solve();
    return 0;
}