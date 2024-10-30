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

class DSekretniiSanta {
 public:
  void solveOne() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
      --x;
    }
    vector<vector<int>> incom(n);
    for (int i =0 ; i < n; ++i) incom[a[i]].push_back(i);
    int two = 0;
    while (two < n && incom[two].size() < 2) ++two;
    if (two == n) {
      cout << n << "\n";
      for (auto x : a) {
        cout << x + 1 << " ";
      }
      cout << "\n";
    } else {
      int atLeastOne = 0;
      for (int i = 0; i < n; ++i) if (!incom[i].empty()) ++atLeastOne;
      cout << atLeastOne << "\n";
      for (int step = 0; step < 2; ++step) {
        vector<int> b(n, -1);
        for (int i = 0; i < n; ++i) if (!incom[i].empty()) {
          int pos = 0;
          if (i == two) pos = step;
          b[incom[i][pos]] = i;
        }
        vector<int> both;
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < n; ++i) {
          bool isLeft = b[i] < 0;
          bool isRight = incom[i].empty();
          if (isLeft && isRight) both.push_back(i); else if (isLeft) left.push_back(i); else if (isRight) right.push_back(i);
        }
        if (!left.empty()) {
          for (int x : both) left.push_back(x);
          vector<int> nright;
          for (int x : both) nright.push_back(x);
          for (int x : right) nright.push_back(x);
          right = nright;
          for (int i = 0; i < left.size(); ++i) b[left[i]] = right[i];
        } else if (both.size() >= 2) {
          for (int i = 0; i < both.size(); ++i) b[both[i]] = both[(i + 1) % both.size()];
        } else {
          continue;
        }
        for (int x : b) {
          cout << x + 1 << " ";
        }
        cout << "\n";
        return;
      }
      assert(false);
    }
  }

  void solve() {
    int nt;
    cin >> nt;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    DSekretniiSanta solver;


    solver.solve();
    return 0;
}