// b-turn-the-rectangles.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define pb push_back
#define fs first
#define sn second
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<long, long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
template <typename C> int sz(C &v) { return v.size(); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1;
int N,
    H[MN], W[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    int pre = INF;
    for (auto i = 0; i < N; i++) {
        cin >> (H[i]) >> (W[i]);
        if (H[i] < W[i]) swap(H[i], W[i]);
        if (H[i] > pre) swap(H[i], W[i]);
        pre = H[i];
    }

    for (auto i = 1; i < N; i++) {
        if (H[i] > H[i - 1]) {
            cout << ("NO") << '\n';
            return 0;
        }
    }
    cout << ("YES") << '\n';

    return 0;
}