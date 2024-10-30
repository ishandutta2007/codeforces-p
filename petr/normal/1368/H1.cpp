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

class TaskH1 {
 public:
  int solveOneDirection(const vector<string>& s) {
    int totalr = 0;
    int totalb = 0;
    for (const string& x : s) {
      for (char c : x) {
        if (c == 'R') ++totalr; else ++totalb;
      }
    }
    int res = min(totalr, totalb);
    int height = s[0].size();
    vector<int> best(2, res);
    int nr = 0;
    int nb = 0;
    for (char c : s[0]) {
      if (c == 'R') ++nr; else ++nb;
    }
    if (s[2][0] == 'R') ++nr; else ++nb;
    if (s[3][0] == 'R') ++nr; else ++nb;
    for (int pos = 1; pos < s[2].size(); ++pos) {
      int cur = min(nr, nb) + height;
      cur = min(cur, best[0] + height);
      cur = min(cur, best[1] + height);
      res = min(res, cur + min(totalr - nr, totalb - nb));
      best[0] = min(best[0], cur);
      best[1] = min(best[1], cur);
      if (s[2][pos] == 'R') {
        ++nr;
        ++best[0];
      } else {
        ++nb;
        ++best[1];
      }
      if (s[3][pos] == 'R') {
        ++nr;
        ++best[0];
      } else {
        ++nb;
        ++best[1];
      }
    }
    return res;
  }

  void solveOne(istream &in, ostream &out) {
    int n, m, q;
    in >> n >> m >> q;
    vector<string> sides(4);
    for (int i = 0; i < 4; ++i) {
      in >> sides[i];
    }
    int res = solveOneDirection(sides);
    vector<string> sides2;
    for (int i = 0; i < 4; ++i) {
      sides2.push_back(sides[(2 + i) % 4]);
    }
    res = min(res, solveOneDirection(sides2));
    out << res << "\n";
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
  TaskH1 solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}