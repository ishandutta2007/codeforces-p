/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
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
//#include "../atcoder/all"

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef pair<int, int> ii;

constexpr int INF = (int) 1.1e9;

class DItsABirdNoItsAPlaneNoItsAaParsa {
 public:
  void solveOne() {
    int n, m;
    cin >> n >> m;
    vector<vector<ii>> jumps(n);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      jumps[a].emplace_back(b, c);
    }
    vector<vector<int>> quickest(n, vector<int>(n, INF));
    for (int from = 0; from < n; ++from) {
      for (ii jump : jumps[from]) {
        quickest[from][jump.first] = min(quickest[from][jump.first], jump.second);
      }
      for (int iter = 0; iter < 2; ++iter) {
        for (int i = 0; i < n; ++i) {
          int j = (i + 1) % n;
          quickest[from][j] = min(quickest[from][j], quickest[from][i] + 1);
        }
      }
    }
    for (int source = 0; source < n; ++source) {
      vector<int> dist(n, INF);
      dist[source] = 0;
      vector<bool> mark(n, false);
      for (int step = 0; step < n; ++step) {
        int bi = -1;
        for (int i = 0; i < n; ++i) if (!mark[i] && (bi < 0 || dist[i] < dist[bi])) {
          bi = i;
        }
        mark[bi] = true;
        int s = dist[bi];
        int dest = s % n;
        for (int i = 0; i < n; ++i) {
          dist[dest] = min(dist[dest], s + quickest[bi][i]);
          ++dest;
          if (dest == n) dest = 0;
        }
      }
      for (int x : dist) cout << x << " ";
      cout << "\n";
    }
  }

  void solve() {
    int nt = 1;
    for (int it = 0; it < nt; ++it) {
      solveOne();
    }
  }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    DItsABirdNoItsAPlaneNoItsAaParsa solver;


    solver.solve();
    return 0;
}