// ./e2-abnormal-permutation-pairs-hard-version.yml
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

/*
 * ax + by = gcd(a, b)
 *
 * we know
 * bx' + (a%b)y' = gcd(a, b)
 *
 * bx' + (a-b*(a//b))y' = gcd(a, b)
 * bx' + ay' - b*(a//b)y' = gcd(a, b)
 * ay' + b(x' - (a//b)y') = gcd(a, b)
 */
template <typename T> T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T x0, y0, res = extgcd(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a / b) * y0;
    return res;
}

// based on Tourist modInt orz
template <typename MD> struct _ModInt {
    using T = typename decay<decltype(MD::value)>::type;
    static_assert(sizeof(T) >= 4, "size of T must be at least 32 bits");
    static_assert(sizeof(T) <= 8, "size of T must be at most 64 bits");
    static_assert(is_integral<T>::value, "T must be an integral type");
#ifdef __SIZEOF_INT128__
    using mul_t = typename conditional<sizeof(T) <= 4, int64_t, __int128>::type;
#else
    using mul_t = int64_t;
    static_assert(sizeof(T) <= 4, "int128 not available, cannot use 64-bit size of T");
#endif

    constexpr static T mod() { return MD::value; }

    template <typename U> static T normalize(const U& x) {
        T res = x;
        res %= mod();
        if (res < 0) res += mod();
        return res;
    }

    T value;
    constexpr _ModInt() : value() {}
    template <typename U> _ModInt(const U& x) { value = normalize(x); }
    const T& operator()() const { return value; }
    template <typename U> operator U() const { return static_cast<U>(value); }

    // FastPow
    template <typename U> static _ModInt pow(_ModInt x, U y) {
        _ModInt res(1);
        for (; y; y /= 2) {
            if (y & 1) res *= x;
            x *= x;
        }
        return res;
    }
    static _ModInt inv(const _ModInt &x) {
        T inv, _; extgcd(x.value, mod(), inv, _);
        return _ModInt(inv);
    }

    // Arithmetic Operators w/ _ModInt
    // Assignment operators here
    _ModInt& operator+=(const _ModInt &o) { if ((value += o.value) >= mod()) value -= mod(); return *this; }
    template <typename U> _ModInt& operator+=(const U &o) { return *this += _ModInt(o); }
    _ModInt& operator-=(const _ModInt &o) { if ((value -= o.value) < 0) value += mod(); return *this; }
    template <typename U> _ModInt& operator-=(const U &o) { return *this -= _ModInt(o); }
    _ModInt& operator++() { return *this += 1; }
    _ModInt operator++(int) { _ModInt res(*this); *this += 1; return res; }
    _ModInt& operator--() { return *this -= 1; }
    _ModInt operator--(int) { _ModInt res(*this); *this -= 1; return res; }
    _ModInt& operator*=(const _ModInt &o) { value = (mul_t)value * o.value % mod(); if (value < 0) value += mod(); return *this; } // make sure cast to mul_t!!!
    template <typename U> _ModInt& operator*=(const U &o) { return *this *= _ModInt(o); }
    _ModInt& operator/=(const _ModInt &o) { return *this *= inv(o.value); }
    template <typename U> _ModInt& operator/=(const U &o) { return *this /= _ModInt(o); }
    _ModInt operator-() const { return _ModInt(value); }
    // Other Operators
    T& operator()() { return value; }
    // Definitions of some operators
};
// Binary operators
#define OP_CMP(op) template <typename T> bool operator op(const _ModInt<T> &lhs, const _ModInt<T> &rhs) { return lhs.value op rhs.value; } \
    template <typename T, typename U> bool operator op(const _ModInt<T> &lhs, U rhs) { return lhs op _ModInt<T>(rhs); } \
    template <typename T, typename U> bool operator op(U lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs) op rhs; }
#define OP_ARI(op) template <typename T> _ModInt<T> operator op(const _ModInt<T> &lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs) op##= rhs; } \
    template <typename T, typename U> _ModInt<T> operator op(U lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs) op##= rhs; } \
    template <typename T, typename U> _ModInt<T> operator op(const _ModInt<T> &lhs, U rhs) { return _ModInt<T>(lhs) op##= rhs; }
OP_CMP(==) OP_CMP(!=) OP_CMP(<) OP_CMP(>) OP_CMP(<=) OP_CMP(>=)
OP_ARI(+) OP_ARI(-) OP_ARI(*) OP_ARI(/)
#undef OP_CMP
#undef OP_ARI
template <typename T> istream& operator>>(istream& in, _ModInt<T> &o) { return in >> o(); }
template <typename T> ostream& operator<<(ostream& out, _ModInt<T> &o) { return out << o(); }

// Definitions
template <typename T, T mod> using ModInt = _ModInt<integral_constant<T, mod>>;

struct VarMod {
    static int value;
};
int VarMod::value;
int& md = VarMod::value;
using MI = _ModInt<VarMod>;

const int MN = 501, D = MN*(MN-1)/2, MINV = 2*D+1;
int N;
MI dp[MN][MINV], C[MN][MN], F[MN]; // dp[i][j] = # permutations of 1..i, j inversions

MI& DP(int i, int j) { return dp[i][j+D]; }

/*
 * transition: append v = 1..i to the front of the permutation, shifting elements forward as necessary
 * overall, appending k will introduce k-1 new inversions
 *
 * we want # of pairs (p,q) s.t. p < q and inv(p) > inv(q)
 *
 * start from a permutation with i-1 elements, we only care about first differing element, which for our pair (p,q) will be represented by a,b
 * from some permutation p w/ inv(p) inversions, we can accept any:
 *
 * a < b
 *
 * AND
 *
 * inv(p) + a-1 > inv(q) + b-1
 * inv(p) + a > inv(q) + b
 * a - b > inv(q) - inv(p)
 * b - a < inv(p) - inv(q)
 *
 * Once we fix # of values, we can also fix inv(p) and inv(q).  Then we count the number of working (a,b) which can be precomputed
 * Pt 2: we really just need to fix inv(p)-inv(q), and sum over all p,q that fit this property, then use our precomputed
 * Pt 3: we can just run FFT on dp here
 *
 * part 1 -> as i
 * part 2 -> as n-j
 *
 * res stored at a[k], k=n+i-j
 * to find ans[k], ask for ans[k+n]
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> VarMod::value;

    // init DP
    DP(0, 0) = DP(1, 0) = 1;
    for (auto i = 2; i <= N; i++) {
        int pMaxInv = (i-1)*(i-2)/2;
        for (auto j = -pMaxInv; j <= pMaxInv; j++) { // propagate
            DP(i, j-i+1) += DP(i-1, j);
            DP(i, j+1) -= 2*DP(i-1, j);
            DP(i, j+i+1) += DP(i-1, j);
        }

        // double!!! prefix sum
        partial_sum(dp[i], dp[i]+MINV, dp[i]);
        partial_sum(dp[i], dp[i]+MINV, dp[i]);
    }

    // init precomp
    C[0][0] = F[0] = 1;
    for (auto i = 1; i <= N; i++) {
        C[i][0] = 1;
        for (auto j = 1; j <= N; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        F[i] = i*F[i-1];
    }

    // fix # of same vals at the start
    MI ans = 0;
    for (auto i = 0; i < N; i++) {
        MI coeff = F[i] * C[N][i]; // Fixing those vals

        int n = N-i-1;
        // cntPairs[k] = Count # pairs (a,b) (1 <= a < b <= n) with diff of k
        vector<MI> cntPairs(n+1);
        for (auto a = 1; a <= n+1; a++)
            for (auto b = a+1; b <= n+1; b++)
                cntPairs[b-a]++;
        partial_sum(all(cntPairs), cntPairs.begin());

        // ans???
        int maxInv = n*(n-1)/2;
        MI curAns = 0;
        for (auto j = max(-maxInv, 1); j <= maxInv; j++)
            curAns += DP(n, j) * cntPairs[min(n, j-1)];

        ans += curAns * coeff;
    }

    cout << (ans) << '\n';

    return 0;
}