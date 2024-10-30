/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

class TaskC {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    set<ii> res;
    for (int i = 0; i <= n; ++i) {
      int s = i % 2 == 0 ? 1 : -1;
      for (int u = 0; u < 3; ++u) {
        for (int v = 0; v < 3; ++v) {
          res.insert(ii(i * 2 + u, s * v));
        }
      }
      res.erase(ii(i * 2 + 1, s));
    }
    out << res.size() << "\n";
    for (const auto& p : res) {
      out << p.first << " " << p.second << "\n";
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
  TaskC solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}