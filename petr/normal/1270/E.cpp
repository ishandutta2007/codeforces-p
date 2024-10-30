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

class TaskE {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    in >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i) {
      in >> x[i] >> y[i];
    }
    for (int bit = 0;; ++bit) {
      vector<int> sa;
      for (int i = 0; i < n; ++i) {
        unsigned int t = x[i] + y[i];
        if (((t >> bit) & 1) == 0) {
          sa.push_back(i + 1);
        }
      }
      if (sa.size() > 0 && sa.size() < n) {
        out << sa.size() << "\n";
        for (int x : sa) {
          out << x << " ";
        }
        out << "\n";
        return;
      }
      sa.clear();
      for (int i = 0; i < n; ++i) {
        unsigned int t = x[i];
        if (((t >> bit) & 1) == 0) {
          sa.push_back(i + 1);
        }
      }
      if (sa.size() > 0 && sa.size() < n) {
        out << sa.size() << "\n";
        for (int x : sa) {
          out << x << " ";
        }
        out << "\n";
        return;
      }
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