/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

#undef NDEBUG

#include <algorithm>
#include <chrono>
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

static uint64_t splitmix64(uint64_t x) {
  // http://xorshift.di.unimi.it/splitmix64.c
  x += 0x9e3779b97f4a7c15;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x ^ (x >> 31);
}

struct myhash_ii {
  size_t operator()(ii p) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64((size_t) 487631741 * (size_t) p.first + (size_t) 436217543 * (size_t) p.second + FIXED_RANDOM);
  }
};

struct myhash_int {
  size_t operator()(int p) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64((size_t) p + FIXED_RANDOM);
  }
};

class ELuchshayaPara {
 public:
  void solveOne() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    unordered_map<int, int, myhash_int> cnt;
    for (auto& x : a) {
      cin >> x;
      ++cnt[x];
    }
    unordered_map<int, vector<int>, myhash_int> by_cnt;
    for (auto p : cnt) {
      by_cnt[p.second].push_back(p.first);
    }
    for (auto& p : by_cnt) {
      sort(all(p.second));
      reverse(all(p.second));
    }
    unordered_set<ii, myhash_ii> bad;
    for (int i = 0; i < m; ++i) {
      int x;
      int y;
      cin >> x >> y;
      bad.emplace(x, y);
      bad.emplace(y, x);
    }
    int64 res = 0;
    for (auto p : cnt) {
      int u = p.first;
      for (const auto& pp : by_cnt) {
        int64 mult = p.second + pp.first;
        for (int v : pp.second) {
          if (u != v && bad.find({u, v}) == bad.end()) {
            res = max(res, mult * (u + v));
            break;
          }
        }
      }
    }
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
    ELuchshayaPara solver;


    solver.solve();
    return 0;
}