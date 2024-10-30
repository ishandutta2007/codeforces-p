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

class CPrivnesiBalans {
 public:
  void solveOne() {
    {
      int n;
      cin >> n;
    }
    string s;
    cin >> s;
    int balance = 0;
    int left = s.size() + 1;
    int right = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        ++balance;
      } else {
        --balance;
      }
      if (balance < 0) {
        left = min(left, i);
        right = max(right, i + 2);
      }
    }
    if (left > right) {
      cout << 0 << "\n";
      return;
    }
    int mleft = 0;
    int mleftat = 0;
    int mmid = 0;
    int mright = 0;
    int mrightat = s.size();
    balance = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        ++balance;
      } else {
        --balance;
      }
      if (i < left) {
        if (balance > mleft) {
          mleft = balance;
          mleftat = i + 1;
        }
      } else if (i < right) {
        mmid = max(mmid, balance);
      } else {
        if (balance > mright) {
          mright = balance;
          mrightat = i + 1;
        }
      }
    }
    if (mleft + mright - mmid >= 0) {
      cout << "1\n";
      cout << (mleftat + 1) << " " << mrightat << "\n";
      return;
    }
    int mx = 0;
    int mat = 0;
    balance = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        ++balance;
      } else {
        --balance;
      }
      if (balance > mx) {
        mx = balance;
        mat = i + 1;
      }
    }
    cout << 2 << "\n";
    cout << 1 << " " << mat << "\n";
    cout << (mat + 1) << " " << s.size() << "\n";
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
    CPrivnesiBalans solver;


    solver.solve();
    return 0;
}