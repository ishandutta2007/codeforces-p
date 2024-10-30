/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom

#include <algorithm>
#include <array>
#include <chrono>
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

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int64_t int64;
typedef uint64_t uint64;
typedef pair<int, int> ii;

typedef vector < vector<int> > graph;
typedef vector<int>::const_iterator const_graph_iter;

class DOddMineralResource {
 public:
  int n;
  vector<int> a;
  graph adj;

  vector<int> lca_h, lca_dfs_list, lca_first, lca_tree;
  vector<char> lca_dfs_used;
  vector<int> tleft;
  vector<int> tright;
  vector<uint64> thash;

  uint64 mod1;
  uint64 mod2;
  uint64 base1;
  uint64 base2;
  vector<uint64> pow1;
  vector<uint64> pow2;
  vector<int> rootFor;

  bool prime(uint64 x) {
    for (uint64 p = 2; p * p <= x; ++p) if (x % p == 0) return false;
    return true;
  }

  DOddMineralResource() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    mod1 = uniform_int_distribution((int) 9e8, (int) 1e9)(rng);
    while (!prime(mod1)) ++mod1;
    base1 = uniform_int_distribution((int) 3137, (int) mod1 - 3137)(rng);
    mod2 = uniform_int_distribution((int) 9e8, (int) 1e9)(rng);
    while (!prime(mod2)) ++mod2;
    base2 = uniform_int_distribution((int) 3137, (int) mod2 - 3137)(rng);
    pow1.resize((int) 3e5 + 10);
    pow1[0] = 1;
    pow2.resize((int) 3e5 + 10);
    pow2[0] = 1;
    for (int i = 1; i < pow1.size(); ++i) {
      pow1[i] = base1 * pow1[i - 1] % mod1;
      pow2[i] = base2 * pow2[i - 1] % mod2;
    }
  }

  void lca_dfs (const graph & g, int v, int h = 1)
  {
    lca_dfs_used[v] = true;
    lca_h[v] = h;
    lca_dfs_list.push_back (v);
    for (const_graph_iter i = g[v].begin(); i != g[v].end(); ++i)
      if (!lca_dfs_used[*i])
      {
        lca_dfs (g, *i, h+1);
        lca_dfs_list.push_back (v);
      }
  }

  void lca_build_tree (int i, int l, int r)
  {
    if (l == r)
      lca_tree[i] = lca_dfs_list[l];
    else
    {
      int m = (l + r) >> 1;
      lca_build_tree (i+i, l, m);
      lca_build_tree (i+i+1, m+1, r);
      if (lca_h[lca_tree[i+i]] < lca_h[lca_tree[i+i+1]])
        lca_tree[i] = lca_tree[i+i];
      else
        lca_tree[i] = lca_tree[i+i+1];
    }
  }

  void lca_prepare (const graph & g, int root)
  {
    int n = (int) g.size();
    lca_h.resize (n);
    lca_dfs_list.reserve (n*2);
    lca_dfs_used.assign (n, 0);

    lca_dfs (g, root);

    int m = (int) lca_dfs_list.size();
    lca_tree.assign (lca_dfs_list.size() * 4 + 1, -1);
    lca_build_tree (1, 0, m-1);

    lca_first.assign (n, -1);
    for (int i = 0; i < m; ++i)
    {
      int v = lca_dfs_list[i];
      if (lca_first[v] == -1)
        lca_first[v] = i;
    }
  }

  int lca_tree_min (int i, int sl, int sr, int l, int r)
  {
    if (sl == l && sr == r)
      return lca_tree[i];
    int sm = (sl + sr) >> 1;
    if (r <= sm)
      return lca_tree_min (i+i, sl, sm, l, r);
    if (l > sm)
      return lca_tree_min (i+i+1, sm+1, sr, l, r);
    int ans1 = lca_tree_min (i+i, sl, sm, l, sm);
    int ans2 = lca_tree_min (i+i+1, sm+1, sr, sm+1, r);
    return lca_h[ans1] < lca_h[ans2] ? ans1 : ans2;
  }

  int lca (int a, int b)
  {
    int left = lca_first[a],
        right = lca_first[b];
    if (left > right)  swap (left, right);
    return lca_tree_min (1, 0, (int)lca_dfs_list.size()-1, left, right);
  }

  int initTree(int left, int right) {
    int at = tleft.size();
    tleft.push_back(-1);
    tright.push_back(-1);
    thash.push_back(0);
    if (left == right) {
    } else {
      int mid = (left + right) / 2;
      tleft[at] = initTree(left, mid);
      tright[at] = initTree(mid + 1, right);
    }
    return at;
  }

  uint64 mergeHashes(uint64 hleft, uint64 hright, int leftSize) {
    uint64 h1 = ((hleft >> 32) + (hright >> 32) * pow1[leftSize]) % mod1;
    uint64 h2 = ((hleft & (((uint64) 1 << 32) - 1)) + (hright & (((uint64) 1 << 32) - 1)) * pow2[leftSize]) % mod2;
    return (h1 << 32) + h2;
  }

  int updateTree(int root, int left, int right, int updAt) {
    int at = tleft.size();
    tleft.push_back(tleft[root]);
    tright.push_back(tright[root]);
    thash.push_back(0);
    if (left == right) {
      assert(left == updAt);
      uint64 one = (((uint64) 1) << 32) + 1;
      if (thash[root] == 0) {
        thash[at] = one;
      } else {
        assert(thash[root] == one);
        thash[at] = 0;
      }
    } else {
      int mid = (left + right) / 2;
      if (updAt <= mid) {
        tleft[at] = updateTree(tleft[root], left, mid, updAt);
      } else {
        tright[at] = updateTree(tright[root], mid + 1, right, updAt);
      }
      thash[at] = mergeHashes(thash[tleft[at]], thash[tright[at]], mid - left + 1);
    }
    return at;
  }

  void walk(int at, int skip, int treeRoot) {
    treeRoot = updateTree(treeRoot, 0, n - 1, a[at]);
    rootFor[at] = treeRoot;
    for (int v : adj[at]) {
      if (v == skip) continue;
      walk(v, at, treeRoot);
    }
  }

  int findDiff(int rootU, int rootV, int left, int right, int needLeft, int needRight) {
    if (needLeft > needRight) return -1;
    if (left == needLeft && right == needRight) {
      if (thash[rootU] == thash[rootV]) {
        return -1;
      }
      if (left == right) {
        return left;
      }
    }
    int mid = (left + right) / 2;
    int c = findDiff(tleft[rootU], tleft[rootV], left, mid, needLeft, min(needRight, mid));
    if (c >= 0) return c;
    return findDiff(tright[rootU], tright[rootV], mid + 1, right, max(mid + 1, needLeft), needRight);
  }

  void solveOne() {
    int q;
    cin >> n >> q;
    a = vector<int>(n);
    for (auto& x : a) {
      cin >> x;
      --x;
    }
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int root = 0;
    lca_prepare(adj, root);
    tleft.clear();
    tright.clear();
    thash.clear();
    int treeRoot = initTree(0, n - 1);
    rootFor = vector<int>(n);
    walk(root, -1, treeRoot);
    for (int qi = 0; qi < q; ++qi) {
      int u, v, l, r;
      cin >> u >> v >> l >> r;
      --u; --v; --l; --r;
      int w = lca(u, v);
      int rootU = rootFor[u];
      int rootV = rootFor[v];
      rootU = updateTree(rootU, 0, n - 1, a[w]);
      int c = findDiff(rootU, rootV, 0, n - 1, l, r);
      if (c >= 0) ++c;
      cout << c << "\n";
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
    DOddMineralResource solver;


    solver.solve();
    return 0;
}