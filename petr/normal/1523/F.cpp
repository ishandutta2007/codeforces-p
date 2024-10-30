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

const int INF = (int) 1.01e9;

class FFavoriteGame {
 public:
  void solveOne() {
    int n, m;
    cin >> n >> m;
    vector<int> xa(n);
    vector<int> ya(n);
    for (int i = 0; i < n; ++i) {
      cin >> xa[i] >> ya[i];
    }
    vector<tuple<int, int, int>> zz(m);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      zz[i] = std::tie(c, a, b);
    }
    sort(all(zz));
    vector<int> xb(m);
    vector<int> yb(m);
    vector<int> target(m);
    for (int i = 0; i < m; ++i) {
      xb[i] = get<1>(zz[i]);
      yb[i] = get<2>(zz[i]);
      target[i] = get<0>(zz[i]);
    }
    vector<int> bestb(m * (1 << n), -INF);
    vector<int> besta((m + 1) * (1 << n), INF);
    priority_queue<pair<int, int>> pqa;
    auto reachb = [&](int at, int mask, int cnt) {
      int code = (at << n) | mask;
      if (cnt > bestb[code]) {
        bestb[code] = cnt;
      }
    };
    for (int i = 0; i < m; ++i) {
      reachb(i, 0, 1);
    }
    auto reacha = [&](int cnt, int mask, int when) {
      int code = (cnt << n) | mask;
      if (when < besta[code]) {
        besta[code] = when;
        pqa.emplace(-when, code);
      }
    };
    for (int i = 0; i < n; ++i) {
      reacha(0, 1 << i, 0);
    }
    vector<vector<int>> shortest(n, vector<int>(1 << n, INF));
    for (int i = 0; i < n; ++i) {
      for (int set = 0; set < (1 << n); ++set) {
        for (int j = 0; j < n; ++j) if (set & (1 << j)) {
          shortest[i][set] = min(shortest[i][set], abs(xa[i] - xa[j]) + abs(ya[i] - ya[j]));
        }
      }
    }
    vector<vector<int>> shortest2(m, vector<int>(1 << n, INF));
    for (int i = 0; i < m; ++i) {
      for (int set = 0; set < (1 << n); ++set) {
        for (int j = 0; j < n; ++j) if (set & (1 << j)) {
            shortest2[i][set] = min(shortest2[i][set], abs(xb[i] - xa[j]) + abs(yb[i] - ya[j]));
          }
      }
    }
    for (int pos = 0; pos < m; ++pos) {
      while (!pqa.empty() && pqa.top().first < target[pos]) {
        auto pair = pqa.top();
        pqa.pop();
        int code = pair.second;
        if (pair.first != -besta[code]) continue;
        int mask = code & ((1 << n) - 1);
        int cnt = code >> n;
        for (int i = 0; i < n; ++i) if (!(mask & (1 << i))) {
          reacha(cnt, mask | (1 << i), -pair.first + shortest[i][mask]);
        }
        for (int i = pos; i < m; ++i) if (target[i] >= -pair.first + shortest2[i][mask]) {
          reachb(i, mask, cnt + 1);
        }
      }
      for (int mask = 0; mask < (1 << n); ++mask) {
        int code = (pos << n) | mask;
        if (bestb[code] >= 1) {
          reacha(bestb[code], mask, target[pos]);
          for (int i = 0; i < n; ++i) if (!(mask & (1 << i))) {
            reacha(bestb[code], mask | (1 << i), target[pos] + abs(xb[pos] - xa[i]) + abs(yb[pos] - ya[i]));
          }
          for (int i = pos + 1; i < m; ++i) if (target[i] >= target[pos] + abs(xb[pos] - xb[i]) + abs(yb[pos] - yb[i])) {
            reachb(i, mask, bestb[code] + 1);
          }
        }
      }
    }
    int res = 0;
    for (int x : bestb) res = max(res, x);
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
    FFavoriteGame solver;


    solver.solve();
    return 0;
}