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

class TaskD {
 public:
  void solveOne(istream &in, ostream &out) {
    int n;
    int k;
    in >> n >> k;
    out << "?";
    for (int i = 0; i < k; ++i) {
      out << " " << i + 1;
    }
    out << "\n";
    out.flush();
    int pos;
    in >> pos;
    --pos;
    int val;
    in >> val;
    out << "?";
    for (int i = 0; i < k; ++i) {
      if (i != pos) {
        out << " " << i + 1;
      }
    }
    out << " " << k + 1 << "\n";
    out.flush();
    int p2;
    in >> p2;
    --p2;
    int v2;
    in >> v2;
    int cnt = 0;
    for (int j = 0; j < k; ++j) {
      if (j != pos) {
        out << "?";
        for (int i = 0; i < k; ++i) {
          if (i != j) {
            out << " " << i + 1;
          }
        }
        out << " " << k + 1 << "\n";
        out.flush();
        int p3;
        in >> p3;
        --p3;
        int v3;
        in >> v3;
        if (v3 == val) {
          ++cnt;
        }
      }
    }
    out << "! ";
    if (v2 > val) {
      out << k - cnt << "\n";
    } else {
      out << 1 + cnt << "\n";
    }
    out.flush();
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
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}