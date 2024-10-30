#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif


#include <cstdio>
#include <iostream>
#include <cmath>
#include <utility>
#include <memory>
#include <memory.h>
#include <cstdlib>
#include <set>
#include <map>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <algorithm>
#include <complex>
#include <vector>


using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<pii>;

#define MAKE_FINAL_NAME_HELPER(A, B) A ## B
#define MAKE_FINAL_NAME(NAME, NUM) MAKE_FINAL_NAME_HELPER(NAME ## _, NUM)
#define ARGUMENTS_SIZE_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, COUNT, ...) COUNT
#define ARGUMENTS_SIZE(...) ARGUMENTS_SIZE_HELPER(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define SELECT_MACRO(NAME, ...) MAKE_FINAL_NAME(NAME, ARGUMENTS_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define pb push_back
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define mp(x, y) make_pair(x, y)

#define ford(...) SELECT_MACRO(ford, __VA_ARGS__)
#define ford_3(i, s, n) for (int i = int(n) - 1; i >= int(s); --i)
#define ford_2(i, n) ford_3(i, 0, n)

#define forn(...) SELECT_MACRO(forn, __VA_ARGS__)
#define forn_3(i, s, n) for (int i = int(s); i < int(n); ++i)
#define forn_2(i, n) forn_3(i, 0, n)

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...)
    #define cerr if (false) cerr
#endif

int n;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    assert(n % 2 == 0);
    return 1;
}

int m;

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int a;
    cin >> a;
    return a;
}

int d(int i) {
    assert(i < m);
    int ai = ask(i);
    int aj = ask(i + m);
    return ai - aj;
}

int sign(int x) {
    return (x > 0) - (x < 0);
}

int solve() {
    m = n / 2;
    int d0 = d(0);
    if (abs(d0) % 2 == 1) {
        return -1;
    }
    if (d0 == 0) {
        return 1;
    }
    int L = -1;
    int R = m;
    while (L != R - 1) {
        int M = (L + R) / 2;
        if (sign(d(M)) == sign(d0)) {
            L = M;
        } else {
            R = M;
        }
    }
    assert(d(R) == 0);
    return R + 1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

//#ifdef LOCAL
//    #define FILE_NAME "a"
//    assert(freopen(FILE_NAME ".in", "r", stdin));
////    freopen(FILE_NAME ".out", "w", stdout);
//#endif

    read();
    int ans = solve();
    cout << "! " << ans << endl;

    return 0;
}