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

class B1Monitoring {
 public:
  void solveOne() {
    int n;
    cin >> n;
    map<int, int64> bySize;
    map<ii, int64> byExact;
    for (int i = 0; i < n; ++i) {
      int w, h;
      cin >> w >> h;
      ++bySize[w];
      ++bySize[h];
      ++byExact[{min(h, w), max(h, w)}];
    }
    int64 res = 0;
    for (auto p : bySize) {
      auto size = p.first;
      auto squares = byExact[{size, size}];
      auto cnt = p.second - squares;
      res += cnt * (cnt - 1) / 2;
    }
    for (auto p : byExact) {
      if (p.first.first != p.first.second) {
        auto cnt = p.second;
        res -= cnt * (cnt - 1) / 2;
      }
    }
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
    B1Monitoring solver;


    solver.solve();
    return 0;
}