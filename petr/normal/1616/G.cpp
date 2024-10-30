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

class GProstoDobavRebro {
 public:
  void solveOne() {
    int n, m;
    cin >> n >> m;
    n += 2;
    vector<vector<int>> outgo(n);
    vector<vector<int>> incom(n);
    vector<bool> have(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      if (a + 1 == b) {
        have[a] = true;
      } else {
        outgo[a].push_back(b - 1);
        incom[b - 1].push_back(a);
      }
    }
    have[0] = have[n - 2] = true;
    for (int i = 1; i < n - 2; ++i) {
      outgo[0].push_back(i);
      incom[i].push_back(0);
      outgo[i].push_back(n - 2);
      incom[n - 2].push_back(i);
    }
    bool allHave = true;
    for (int i = 0; i < n - 1; ++i) if (!have[i]) allHave = false;
    if (allHave) {
      cout << (n - 2) * (int64) (n - 3) / 2 << "\n";
      return;
    }
    vector<int> nots;
    vector<int> haveCount(n);
    for (int i = n - 2; i >= 0; --i) {
      if (have[i]) haveCount[i] = 1 + haveCount[i + 1]; else {
        nots.push_back(i);
      }
    }
    reverse(all(nots));

    vector<bool> mark(2 * n);

    auto forward = [&](auto self, int at, int right) {
      if (at < 0) return;
      mark[at] = true;
      int v = at / 2;
      int p = at % 2;
      int np = p ^ 1;
      for (int x : outgo[v]) {
        if (x <= right && !mark[x * 2 + np]) {
          self(self, x * 2 + np, right);
        }
      }
    };

    auto backward = [&](auto self, int at) {
      if (at < 0) return;
      mark[at] = true;
      int v = at / 2;
      int p = at % 2;
      int np = p ^ 1;
      for (int x : incom[v]) {
        if (!mark[x * 2 + np]) {
          self(self, x * 2 + np);
        }
      }
    };

    bool canSame = true;
    bool canDiff = false;

    for (int i = 0; i + 1 < nots.size(); ++i) {
      mark[nots[i + 1] * 2] = false;
      mark[nots[i + 1] * 2 + 1] = false;
      forward(forward, nots[i] * 2, nots[i + 1]);
      bool ncanSame = false;
      bool ncanDiff = false;
      if (mark[nots[i + 1] * 2]) {
        ncanSame |= canSame;
        ncanDiff |= canDiff;
      }
      if (mark[nots[i + 1] * 2 + 1]) {
        ncanSame |= canDiff;
        ncanDiff |= canSame;
      }
      canSame = ncanSame;
      canDiff = ncanDiff;
    }

    mark[nots.back() * 2] = false;
    mark[nots.back() * 2 + 1] = false;
    forward(forward, nots.back() * 2, n);
    vector<int64> rways(4);
    for (int i = nots.back(); i <= n - 2; ++i) {
      int code = 0;
      if (mark[i * 2]) code += 1;
      if (mark[i * 2 + 1]) code += 2;
      ++rways[code];
    }

    mark[nots[0] * 2] = false;
    mark[nots[0] * 2 + 1] = false;
    backward(backward, nots[0] * 2);
    vector<int64> lways(4);
    for (int i = 0; i <= nots[0]; ++i) {
      int code = 0;
      if (mark[i * 2]) code += 1;
      if (mark[i * 2 + 1]) code += 2;
      ++lways[code];
    }
    int64 res = 0;
    for (int lcode = 1; lcode < 4; ++lcode) {
      for (int rcode = 1; rcode < 4; ++rcode) {
        bool ok = false;
        if (canSame) {
          if (lcode & rcode) {
            ok = true;
          }
        }
        if (canDiff) {
          int nrcode = 0;
          if (rcode & 1) nrcode += 2;
          if (rcode & 2) nrcode += 1;
          if (lcode & nrcode) {
            ok = true;
          }
        }
        if (ok) {
          res += lways[lcode] * rways[rcode];
        }
      }
    }
    if (nots.size() == 1) --res;
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
    GProstoDobavRebro solver;


    solver.solve();
    return 0;
}