#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

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

struct Data {
    int sub = 0, ev = 0, odd = 0;
    Data() {}
};
Data add(Data a, Data b) {
    a.sub += b.sub;
    a.ev += b.odd;
    a.odd += b.ev;
    return a;
}
Data sub(Data a, Data b) {
    a.sub -= b.sub;
    a.ev -= b.odd;
    a.odd -= b.ev;
    return a;
}

int n;
num a[MAXN], ans = 0;
vector<int> adj[MAXN];
Data dp_down[MAXN], sum[MAXN], dp_up[MAXN];

void dfs_down(int c, int p) {
    for (auto nxt : adj[c]) if (nxt != p) dfs_down(nxt, c);
    dp_down[c] = Data();
    for (auto nxt : adj[c]) if (nxt != p) {
        ans += (a[c] * dp_down[nxt].odd - a[c] * dp_down[nxt].ev) * (n - dp_down[nxt].sub);
        dp_down[c] = add(dp_down[c], dp_down[nxt]);
        sum[c] = add(sum[c], dp_down[nxt]);
    }
    dp_down[c].ev++;
    dp_down[c].sub++;
}
void dfs_up(int c, int p, Data me) {
    if (p != -1) {
        dp_up[c] = dp_up[p];
        dp_up[c].ev += me.ev, dp_up[c].odd += me.odd, dp_up[c].sub += me.sub;

        swap(dp_up[c].ev, dp_up[c].odd);
        num cur = (-a[c] * dp_up[c].odd + a[c] * dp_up[c].ev) * (n - dp_up[c].sub);
        ans += cur;
    }
    dp_up[c].ev++;
    dp_up[c].sub++;
    for (auto nxt : adj[c]) if (nxt != p) dfs_up(nxt, c, sub(sum[c], dp_down[nxt]));
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs_down(0, -1);
    dfs_up(0, -1, Data());
    for (int i = 0; i < n; i++) ans += a[i] * n;

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}