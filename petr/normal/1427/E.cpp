/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
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

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class TaskE {
 public:
  vector<char> op;
  vector<int64> a;
  vector<int64> b;

  int64 add(int64 x, int64 y) {
    op.push_back('+');
    a.push_back(x);
    b.push_back(y);
    return x + y;
  }

  int64 xorr(int64 x, int64 y) {
    op.push_back('^');
    a.push_back(x);
    b.push_back(y);
    return x ^ y;
  }

  void solveOne(istream &in, ostream &out) {
    int64 x;
    in >> x;
    int p2 = 0;
    while (1 << (p2 + 1) <= x) ++p2;
    int64 x2 = x;
    for (int i = 0; i < p2; ++i) x2 = add(x2, x2);
    int64 y = xorr(add(x2, x), xorr(x2, x));
    int64 t;
    if ((y & (y - 1)) == 0) {
      t = y;
    } else {
      y = xorr(y, add(y, y));  // has exactly two "1" bits
      int64 z = y;
      do {
        z = add(z, z);
      } while ((z & y) == 0);
      t = xorr(add(z, y), xorr(z, y));
    }
    assert((t & (t - 1)) == 0);
    while (t > 1 && x > 1) {
      if (t <= x) {
        int64 v = t;
        while (v <= x) {
          if ((x & v) != 0) {
            x = xorr(x, v);
          }
          if (v <= x) v = add(v, v);
        }
      }
      assert(x < t);
      if (x == 1) break;
      int64 v = x;
      while ((v & (v - 1)) != 0) {
        v = add(v, v);
        if ((v & t) != 0) {
          v = xorr(v, t);
        }
      }
      t = v;
    }
    out << op.size() << "\n";
    for (int i = 0; i < op.size(); ++i) {
      out << a[i] << " " << op[i] << " " << b[i] << "\n";
    }
  }

  void solve(std::istream &in, std::ostream &out) {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne(in, out);
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  TaskE solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}