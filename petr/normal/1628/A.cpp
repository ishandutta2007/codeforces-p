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

class AMeximumArray {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (int x : a) ++cnt[x];
    int s0 = 0;
    while (cnt[s0]) ++s0;
    vector<int> b;
    int pos = 0;
    vector<int> cur(n + 1);
    while (pos < n) {
      b.push_back(s0);
      int ncur = 0;
      int spos = pos;
      bool any = false;
      while (!any || ncur < b.back()) {
        any = true;
        ++cur[a[pos]];
        if (a[pos] < b.back() && cur[a[pos]] == 1) ++ncur;
        --cnt[a[pos]];
        if (cnt[a[pos]] == 0) {
          s0 = min(s0, a[pos]);
        }
        ++pos;
      }
      for (int i = spos; i < pos; ++i) {
        --cur[a[i]];
      }
    }
    cout << b.size() << "\n";
    for (int x : b) cout << x << " ";
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
    AMeximumArray solver;


    solver.solve();
    return 0;
}