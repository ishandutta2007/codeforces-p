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

class TaskE {
 public:
  void solveOne(istream &in, ostream &out) {
    int m, n;
    in >> m >> n;
    vector<int64> a(m);
    for (auto& x : a) in >> x;
    vector<int64> b(n);
    for (auto& x : b) in >> x;
    vector<tuple<int64, int, int>> s;
    for (int i = 0; i < m; ++i) {
      int len; in >> len;
      for (int j = 0; j < len; ++j) {
        int v;
        in >> v;
        --v;
        s.emplace_back(a[i] + b[v], i, v);
      }
    }
    sort(all(s));
    reverse(all(s));
    vector<int> what(n, -1);
    vector<int> p(m);
    for (int i = 0; i < m; ++i) p[i] = i;
    int64 res = 0;
    for (const auto& t : s) {
      int i = get<1>(t);
      int j = get<2>(t);
      if (what[j] < 0) {
        what[j] = i;
      } else {
        int va = rget(p, what[j]);
        int vb = rget(p, i);
        if (va != vb) {
          p[va] = vb;
        } else {
          res += get<0>(t);
        }
      }
    }
    out << res << "\n";
  }

  int rget(vector<int>& p, int i) {
    int r = i;
    while (p[r] != r) r = p[r];
    int t = i;
    while (p[t] != r) {
      int n = p[t];
      p[t] = r;
      t = n;
    }
    return r;
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