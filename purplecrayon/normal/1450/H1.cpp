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

num fact[N], ifact[N];

num po(num b, int p) {
    num ans = 1;
    for (; p; b *= b, p /= 2) if (p & 1) ans *= b;
    return ans;
}
void pre() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1]*i;
    ifact[N-1] = inv(fact[N-1]);
    for (int i = N-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k) {
    return fact[n] * ifact[k] * ifact[n-k];
}

void solve() {
    // abs(W's on odd positions - W's on even positions) / 2
    // x = ?'s on odds and y = ?'s on evens
    //
    // sum { (x choose i) * (y choose j) * (d + x - y) / 2 } over (i, j) 
    //
    // flip every other bit, now it's
    // abs(B's on odd positions - W's on even positions) / 2
    // abs((n / 2 - W's on odd positions) - W's on even positions) / 2
    // abs(n / 2 - W) / 2

    int n, m; cin >> n >> m;
    assert(m == 0);
    string s; cin >> s;
    for (int i = 1; i < n; i += 2) {
        if (s[i] != '?')
            s[i] ^= 'b' ^ 'w';
    }

    int cnt_q = 0, cnt_w = 0;
    for (char c : s) {
        cnt_q += (c == '?');
        cnt_w += (c == 'w');
    }

    num cnt = po(2, cnt_q - 1); // the last is determined by everything else to make parities work out
    num sum = 0;
    for (int w = cnt_w; w <= cnt_w + cnt_q; w++) {
        if (w % 2 == (n / 2) % 2) {
            sum += nck(cnt_q, w - cnt_w) * abs(n / 2 - w) / 2;
        }
    }
    cout << (sum / cnt) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}