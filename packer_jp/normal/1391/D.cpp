#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int sign(int x) { return (x > 0) - (x < 0); }
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

signed main() {
    int n, m;
    cin >> n >> m;
    if (n == 1) { fin(0); }
    if (n >= 4) { fin(-1); }
    vector<string> a(n);
    rep(i, n) { cin >> a[i]; }
    vvint dp(m + 1, vint(bit(n), INT_MAX));
    rep(i, bit(n)) { dp[0][i] = 0; }
    vvint ok(bit(n), vint(bit(n), 1));
    rep(i, bit(n)) {
        rep(j, bit(n)) {
            if (n == 2) { ok[i][j] = (__builtin_popcountll(i) + __builtin_popcountll(j)) & 1; }
            if (n == 3) {
                ok[i][j] &= (__builtin_popcountll(i % 4) + __builtin_popcountll(j % 4)) & 1;
                ok[i][j] &= (__builtin_popcountll(i / 2) + __builtin_popcountll(j / 2)) & 1;
            }
        }
    }
    rep(i, m) {
        int pre = 0;
        rep(j, n) { pre += (a[j][i] - '0') << j; }
        rep(j, bit(n)) {
            rep(k, bit(n)) {
                if (ok[j][k]) { chmin(dp[i + 1][k], dp[i][j] + __builtin_popcountll(pre ^ k)); }
            }
        }
    }
    int ans = INT_MAX;
    rep(i, bit(n)) { chmin(ans, dp[m][i]); }
    cout << ans << endl;

}