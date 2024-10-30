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

class FVishki {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<ii> h(n);
    for (int i = 0; i < n; ++i) {
      cin >> h[i].first;
      h[i].second = i;
    }
    sort(all(h));
    reverse(all(h));
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    vector<int> left(n, -1);
    vector<int> right(n, -1);
    vector<int> byLeft(n, -1);
    vector<int> tag(n, -1);
    int time = 0;
    auto dfs = [&](auto self, int x, int skip, int ctag) -> void {
      byLeft[time] = x;
      left[x] = time;
      tag[x] = ctag;
      ++time;
      for (int y : adj[x]) {
        if (y == skip) continue;
        self(self, y, x, ctag < 0 ? y : ctag);
      }
      right[x] = time;
    };
    int root = h[0].second;
    dfs(dfs, root, -1, -1);
    int64 res = 0;
    int got = 0;
    int parts = 0;
    vector<bool> seen(n);
    int sofar = 0;
    set<int> active;
    for (auto p : h) {
      int at = p.second;
      if (tag[at] >= 0 && !seen[tag[at]]) {
        seen[tag[at]] = true;
        ++parts;
        if (parts == 2) {
          res += h[0].first - p.first;
        }
      }
      auto it = active.lower_bound(left[at]);
      bool done = false;
      if (it != active.end()) {
        if (*it < right[at]) {
          done = true;
        }
      }
      if (done) continue;
      if (it != active.begin()) {
        --it;
        if (right[byLeft[*it]] > left[at]) {
          active.erase(it);
          --sofar;
        }
      }
      active.insert(left[at]);
      ++sofar;
      if (sofar > got) {
        ++got;
        res += p.first;
      }
    }
    assert(parts >= 1);
    if (parts == 1) res += h[0].first;
    cout << res << "\n";
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
    FVishki solver;


    solver.solve();
    return 0;
}