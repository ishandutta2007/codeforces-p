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

class TaskA {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    int m;
    in >> n >> m;
    vector<int> l(m);
    for (int& a : l) in >> a;
    int64 remainingTotal = 0;
    for (int a : l) remainingTotal += a;
    if (remainingTotal < n) {
      out << -1 << "\n";
      return;
    }
    vector<int> p(m);
    int lastEmpty = n - 1;
    for (int i = m - 1; i >= 0; --i) {
      remainingTotal -= l[i];
      if (remainingTotal < lastEmpty) {
        lastEmpty = remainingTotal;
      }
      if (lastEmpty + l[i] > n) {
        lastEmpty = n - l[i];
      }
      if (lastEmpty < 0) {
        out << -1 << "\n";
        return;
      }
      p[i] = lastEmpty;
      --lastEmpty;
    }
    assert(lastEmpty == -1);
    for (int x : p) {
      out << x + 1 << " ";
    }
    out << "\n";
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
  TaskA solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}