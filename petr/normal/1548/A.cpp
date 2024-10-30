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

class AWebOfLies {
 public:
  void solveOne() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> a(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      a[u].insert(v);
      a[v].insert(u);
    }
    vector<int> cnt(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j : a[i]) {
        if (j > i) ++cnt[i];
      }
      if (cnt[i] == 0) {
        ++res;
      }
    }
    int q;
    cin >> q;
    for (int qi = 0; qi < q; ++qi) {
      int kind;
      cin >> kind;
      if (kind == 3) {
        cout << res << "\n";
      } else {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (u < v) swap(u, v);
        if (kind == 1) {
          a[u].insert(v);
          a[v].insert(u);
          if (cnt[v] == 0) --res;
          ++cnt[v];
        } else {
          a[u].erase(v);
          a[v].erase(u);
          --cnt[v];
          if (cnt[v] == 0) ++res;
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
    AWebOfLies solver;


    solver.solve();
    return 0;
}