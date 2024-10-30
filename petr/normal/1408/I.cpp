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
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MODULO = 998244353;
const uint64 HALF = ((uint64) 1) << 63;
const uint64 BIG = HALF - HALF % (uint64) MODULO;

class TaskI {
 public:
  int normalize(int x) {
    int tail = x & 15;
    x >>= 4;
    if (x > 0) {
      int without_last = x & (x - 1);
      int last = x ^ without_last;
      return (last << 4) + tail;
    } else {
      return tail;
    }
  }

  int n, k, c;
  vector<vector<int>> prob;
  vector<vector<uint64>> nprob;
  vector<vector<int64>> comb;
  vector<vector<int64>> tricky;
  map<pair<int, int>, int64> got;

  void update(int a, int count, int taken, int allowed, int xorv, int64 ways) {
    got[make_pair(taken, xorv)] = (got[make_pair(taken, xorv)] + ways) % MODULO;

    for (int v = min(k - taken, allowed); v >= 1; --v) {
      int nxorv = a ^ (a - v);
      for (int times = 1; times <= count && taken + times * v <= k; ++times) {
        int uxorv = xorv;
        if (times & 1) {
          uxorv ^= nxorv;
        }
        int nways = ways * facts[count] % MODULO * invfacts[times] % MODULO * invfacts[count - times] % MODULO;
        nways = nways * comb[taken + times * v][times * v] % MODULO;
        nways = nways * tricky[times][v] % MODULO;
        update(a, count - times, taken + times * v, v - 1, uxorv, nways);
      }
    }
  }

  vector<int64> invs;
  vector<int64> facts;
  vector<int64> invfacts;

  void solveOne(istream &in, ostream &out) {
    /*set<int> seen;
    for (int i = 0; i < (1 << 16); ++i) {
      seen.insert(normalize(i));
    }
    cerr << seen.size() << endl;*/

    in >> n >> k >> c;

    invs = vector<int64>((1 << c) + 2);
    invs[1] = 1;
    for (int i = 2; i < invs.size(); ++i) {
      invs[i] = ((MODULO - (MODULO / i) * invs[MODULO % i] % MODULO) % MODULO);
    }
    facts = vector<int64>(invs.size());
    invfacts = vector<int64>(invs.size());
    facts[0] = 1;
    invfacts[0] = 1;
    for (int i = 1; i < facts.size(); ++i) {
      facts[i] = (facts[i - 1] * i % MODULO);
      invfacts[i] = (invfacts[i - 1] * invs[i] % MODULO);
    }

    comb = vector<vector<int64>>(k + 1, vector<int64>(k + 1));
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j <= i; ++j) {
        comb[i][j] = facts[i] * invfacts[j] % MODULO * invfacts[i - j] % MODULO;
      }
    }
    tricky = vector<vector<int64>>(k + 1, vector<int64>(k + 1));
    for (int count = 1; count <= k; ++count) {
      tricky[0][count] = 1;
    }
    for (int slots = 1; slots <= k; ++slots) {
      for (int count = 1; slots * count <= k; ++count) {
        tricky[slots][count] = comb[slots * count][count] * tricky[slots - 1][count] % MODULO;
      }
    }

    vector<int> a(n);
    int extra = 0;
    for (int i = 0; i < n; ++i) {
      in >> a[i];
      extra ^= a[i];
      a[i] = normalize(a[i]);
    }
    prob = vector<vector<int>>(k + 1, vector<int>(1 << c));
    nprob = vector<vector<uint64>>(k + 1, vector<uint64>(1 << c));
    prob[0][0] = 1;
    sort(all(a));
    for (int i = 0; i < a.size();) {
      int j = i;
      while (j < a.size() && a[j] == a[i]) ++j;
      //j = i + 1;
      int count = j - i;
      got.clear();
      update(a[i], count, 0, k, 0, 1);
      vector<int> maxes(k + 1);
      for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < (1 << c); ++j) {
          if (prob[i][j]) {
            maxes[i] = j + 1;
          }
        }
      }
      for (auto& v : nprob) fill(all(v), 0);
      for (int taken = 0; taken <= k; ++taken) {
        for (int old = 0; old + taken <= k; ++old) {
          for (const auto &it : got) {
            if (taken != it.first.first) continue;
            int xorv = it.first.second;
            int64 ways = it.second;
            uint64 cw = ways * comb[old + taken][taken] % MODULO;
            for (int ov = 0; ov < maxes[old]; ++ov) {
              int nv = ov ^xorv;
              auto &res = nprob[old + taken][nv];
              res += prob[old][ov] * cw;
              if (res >= HALF) res -= BIG;
            }
          }
        }
      }
      for (int old = 0; old <= k; ++old) {
        for (int ov = 0; ov < (1 << c); ++ov) {
          prob[old][ov] = nprob[old][ov] % MODULO;
        }
      }
      i = j;
    }

    int64 denom = 1;
    for (int i = 0; i < k; ++i) {
      denom = denom * invs[n] % MODULO;
    }
    for (int i = 0; i < (1 << c); ++i) {
      int j = i ^ extra;
      int64 val = prob[k][j] * denom % MODULO;
      out << val << " ";
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
  TaskI solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}