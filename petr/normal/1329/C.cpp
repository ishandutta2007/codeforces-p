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
    int h;
    int g;
    in >> h >> g;
    vector<int> a((1 << h));
    for (int i = 1; i < a.size(); ++i) {
      in >> a[i];
    }
    vector<int> size(1 << h, 1);
    vector<int> need(1 << h);
    for (int i = 1; i < (1 << g); ++i) {
      need[i] = 1;
    }
    for (int i = size.size() - 1; i > 1; --i) {
      size[i / 2] += size[i];
      need[i / 2] += need[i];
    }
    assert(size[1] == (1 << h) - 1);
    assert(need[1] == (1 << g) - 1);
    vector<int> p;
    for (int root = 1; root < (1 << g); ++root) {
      while (true) {
        bool ok = true;
        int i = root;
        while (i < a.size() && a[i] != 0) {
          if (size[i] == need[i]) {
            ok = false;
            break;
          }
          if (2 * i >= a.size()) {
            break;
          }
          if (a[2 * i] > a[2 * i + 1]) {
            i = 2 * i;
          } else {
            i = 2 * i + 1;
          }
        }
        if (!ok) break;
        p.push_back(root);
        i = root;
        {
          int j = i / 2;
          while (j > 0) {
            --size[j];
            j = j / 2;
          }
        }
        while (i < a.size() && a[i] != 0) {
          --size[i];
          if (2 * i >= a.size()) {
            a[i] = 0;
            break;
          }
          if (a[2 * i] > a[2 * i + 1]) {
            a[i] = a[2 * i];
            i = 2 * i;
          } else {
            a[i] = a[2 * i + 1];
            i = 2 * i + 1;
          }
        }
      }
    }
    for (int i = 1; i < (1 << h); ++i) assert(size[i] == need[i]);
    int64 s = 0;
    for (int i = 1; i < (1 << g); ++i) s += a[i];
    out << s << "\n";
    for (int x : p) out << x << " ";
    out << "\n";
  }

  void solve(std::istream &in, std::ostream &out) {
    int nt;
    in >> nt;
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