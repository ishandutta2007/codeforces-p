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

class BLingvistika {
 public:
  void solveOne() {
    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    string s;
    cin >> s;
    vector<int> cnt(2);
    for (char c : s) ++cnt[c - 'A'];
    if (cnt[0] != a + ab + ba) {
      cout << "NO\n";
      return;
    }
    vector<int> bounds;
    bounds.push_back(0);
    for (int i = 0; i + 1 < s.size(); ++i) if (s[i] == s[i + 1]) {
      bounds.push_back(i + 1);
    }
    bounds.push_back(s.size());
    vector<int> exacta;
    vector<int> exactb;
    int free = 0;
    for (int i = 0; i + 1 < bounds.size(); ++i) {
      int len = bounds[i + 1] - bounds[i];
      int got = (len - 1) / 2;
      free += got;
      if (len % 2 == 0) {
        if (s[bounds[i]] == 'A') {
          exacta.push_back(got + 1);
        } else {
          exactb.push_back(got + 1);
        }
      }
    }
    sort(all(exacta));
    sort(all(exactb));
    int extraa = 0;
    int extrab = 0;
    int tmp = ab;
    while (extraa < exacta.size() && exacta[extraa] <= tmp) {
      tmp -= exacta[extraa];
      ++extraa;
    }
    tmp = ba;
    while (extrab < exactb.size() && exactb[extrab] <= tmp) {
      tmp -= exactb[extrab];
      ++extrab;
    }
    if (free + extraa + extrab >= ab + ba) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
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
    BLingvistika solver;


    solver.solve();
    return 0;
}