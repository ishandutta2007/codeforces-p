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

constexpr int INF = (int) 1e9;

class CKeshiInSearchOfAmShZ {
 public:
  void solveOne() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> incom(n);
    vector<int> todo(n);
    for (int i = 0; i < m; ++i) {
      int a;
      int b;
      cin >> a >> b;
      --a; --b;
      incom[b].push_back(a);
      ++todo[a];
    }
    priority_queue<pair<int, int>> pq;
    vector<int> d(n, INF);
    d[n - 1] = 0;
    pq.emplace(0, n - 1);
    while (!pq.empty()) {
      auto pp = pq.top();
      pq.pop();
      int cur = pp.second;
      if (pp.first != -d[cur]) continue;
      for (auto x : incom[cur]) {
        --todo[x];
        int got = todo[x] + d[cur] + 1;
        if (got < d[x]) {
          d[x] = got;
          pq.emplace(-got, x);
        }
      }
    }
    cout << d[0] << "\n";
  }

  void solve() {
    int nt = 1;
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
    CKeshiInSearchOfAmShZ solver;


    solver.solve();
    return 0;
}