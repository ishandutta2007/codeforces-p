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

vector<set<ii>> pairs(26 * 26);
vector<set<int>> singles(26);

class TaskD {
 public:
  vector<ii> innerSolve(int size, vector<pair<int, char>> bads) {
    set<int> remains;
    for (int i = 0; i < bads.size(); ++i) {
      int u = bads[i].second - 'a';
      singles[u].insert(i);
      remains.insert(i);
    }
    for (int i = 0; i + 1 < bads.size(); ++i) {
      int u = bads[i].second - 'a';
      int v = bads[i + 1].second - 'a';
      if (u != v) {
        pairs[u * 26 + v].emplace(i, i + 1);
      }
    }
    set<ii> counts;
    for (int i = 0; i < 26; ++i) if (!singles[i].empty()) {
      counts.emplace(singles[i].size(), i);
    }
    vector<ii> res;
    while (!counts.empty()) {
      auto p = *counts.rbegin();
      int u = p.second;
      ii pp(-1, -1);
      for (int v = 0; v < 26; ++v) {
        if (!pairs[u * 26 + v].empty()) {
          pp = *pairs[u * 26 + v].begin();
        } else if (!pairs[v * 26 + u].empty()) {
          pp = *pairs[v * 26 + u].begin();
        }
        if (pp.first < 0) continue;
        res.emplace_back(bads[pp.first].first, bads[pp.second].first);
        assert(1 == remains.erase(pp.first));
        assert(1 == remains.erase(pp.second));
        {
          int i = pp.first;
          int u = bads[i].second - 'a';
          assert(1 == counts.erase(ii(singles[u].size(), u)));
          assert(1 == singles[u].erase(i));
          if (!singles[u].empty()) counts.insert(ii(singles[u].size(), u));
        }
        {
          int i = pp.second;
          int u = bads[i].second - 'a';
          assert(1 == counts.erase(ii(singles[u].size(), u)));
          assert(1 == singles[u].erase(i));
          if (!singles[u].empty()) counts.insert(ii(singles[u].size(), u));
        }
        {
          int i = pp.first;
          int j = pp.second;
          int u = bads[i].second - 'a';
          int v = bads[j].second - 'a';
          assert(1 == pairs[u * 26 + v].erase(ii(i, j)));
        }
        auto it = remains.lower_bound(pp.first);
        int prev = -1;
        int next = -1;
        if (it != remains.end()) {
          next = *it;
          {
            int i = pp.second;
            int j = next;
            int u = bads[i].second - 'a';
            int v = bads[j].second - 'a';
            if (u != v) {
              assert(1 == pairs[u * 26 + v].erase(ii(i, j)));
            }
          }
        }
        if (it != remains.begin()) {
          prev = *(--it);
          {
            int i = prev;
            int j = pp.first;
            int u = bads[i].second - 'a';
            int v = bads[j].second - 'a';
            if (u != v) {
              assert(1 == pairs[u * 26 + v].erase(ii(i, j)));
            }
          }
        }
        if (prev >= 0 && next >= 0) {
          int i = prev;
          int j = next;
          int u = bads[i].second - 'a';
          int v = bads[j].second - 'a';
          if (u != v) {
            pairs[u * 26 + v].emplace(i, j);
          }
        }
        break;
      }
      if (pp.first < 0) {
        assert(1 == counts.size());
        assert(!singles[u].empty());
        for (int i : singles[u]) {
          res.emplace_back(bads[i].first, bads[i].first + 1);
        }
        singles[u].clear();
        break;
      }
    }
    res.emplace_back(0, size);
    return res;
  }

  void fenwickUpd(vector<int>& f, int at, int by) {
    while (at < f.size()) {
      f[at] += by;
      at |= at + 1;
    }
  }

  int fenwickGet(vector<int>& f, int upto) {
    int res = 0;
    while (upto >= 0) {
      res += f[upto];
      upto = (upto & (upto + 1)) - 1;
    }
    return res;
  }

  void solveOne(istream &in, ostream &out) {
    string a;
    in >> a;
    vector<pair<int, char>> bads;
    for (int i = 0; i + 1 < a.size(); ++i) {
      if (a[i] == a[i + 1]) {
        bads.emplace_back(i + 1, a[i]);
      }
    }
    vector<ii> sol = innerSolve(a.size(), bads);
    set<int> alive;
    vector<int> aliveFenwick(a.size());
    for (int i = 0; i < a.size(); ++i) {
      alive.insert(i);
      fenwickUpd(aliveFenwick, i, 1);
    }
    out << sol.size() << "\n";
    vector<int> toRemove;
    for (ii s : sol) {
      out << fenwickGet(aliveFenwick, s.first - 1) + 1 << " " << fenwickGet(aliveFenwick, s.second - 1) << "\n";
      auto it = alive.lower_bound(s.first);
      while (it != alive.end() && *it < s.second) {
        toRemove.push_back(*it);
        ++it;
      }
      for (int x : toRemove) {
        alive.erase(x);
        fenwickUpd(aliveFenwick, x, -1);
      }
      toRemove.clear();
    }
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
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}