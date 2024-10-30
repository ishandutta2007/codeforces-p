#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}
public:
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num = modnum<MOD>;

void solve() {
    int n, m; cin >> n >> m;
    vector<ar<int, 2>> a(n); for (auto& [l, r] : a) cin >> l >> r;
    vector<ar<int, 2>> b(m); for (auto& [x, y] : b) cin >> x >> y, --x, --y;

    vector<int> sum(n + 1);
    auto add = [&](int L, int R) {
        sum[L]++;
        if (R < n)
            sum[R+1]--;
    };
    for (auto& [l, r] : a) {
        add(l, r);
    }
    for (int i = 1; i <= n; i++) sum[i] += sum[i-1];

    vector<num> fact(n + 1, 1), ifact(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
    ifact[n] = 1 / fact[n];
    for (int i = n-1; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1);

    auto nck = [&](int n, int k) -> num {
        if (n < 0 || k < 0 || n < k) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    };

    vector<vector<num>> ps(2 * m + 1, vector<num>(n + 1));
    for (int k = 0; k <= 2 * m; k++) {
        for (int i = 1; i <= n; i++) {
            ps[k][i] = nck(sum[i] - k, i - k) + ps[k][i-1];
        }
    }


    num ans = 0;
    vector<int> vis(n, -1);
    for (int i = 0; i < (1 << m); i++) {
        auto isect = [&](auto x, auto y) {
            return ar<int, 2>{max(x[0], y[0]), min(x[1], y[1])};
        };

        int has = 0;
        ar<int, 2> need{1, n};
        for (int j = 0; j < m; j++) if ((i >> j) & 1) {
            need = isect(need, a[b[j][0]]);
            need = isect(need, a[b[j][1]]);
            if (vis[b[j][0]] != i) has++, vis[b[j][0]] = i;
            if (vis[b[j][1]] != i) has++, vis[b[j][1]] = i;
        }
        if (need[0] > need[1]) continue;

        num cnt = ps[has][need[1]] - ps[has][need[0]-1];

        if (__builtin_popcount(i) % 2 == 0) ans += cnt;
        else ans -= cnt;
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}