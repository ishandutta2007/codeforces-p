#pragma GCC optimize ("O3", "unroll-loops")
//#pragma GCC target ("avx2")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
namespace {
	const int MOD107 = 1000000007;
	const int MOD998 = 998244353;
	using ll = long long;
	using ull = unsigned long long;
	using pii = pair<int, int>;
	using pll = pair<ll, ll>;
	template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
	template <class T> using maxheap = priority_queue<T, vector<T>, less<T>>;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//	mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
	struct Modular {
	private:
		long long MODVALUE = 0;
		long long val = 0;

		Modular initModular(long long val) const { return Modular(val, MODVALUE); }

	#ifdef LOCAL
		inline void validate() const {
			assert(MODVALUE != 0);
		}

		inline void validate(const Modular& other) const {
			assert(MODVALUE != 0);
			assert(MODVALUE == other.MODVALUE);
			other.validate();
		}
	#else
		inline void validate() const { }
		inline void validate(const Modular& other) const { }
	#endif

	public:
		explicit operator long long() const { return val; }

		template<class T> Modular& operator = (const T& other) { val = other; return *this; }
		template<class T> void setMod(const T& MOD) { MODVALUE = MOD; }

		Modular& operator += (const Modular& other) { validate(other); val += other.val; val %= MODVALUE; return *this; }
		Modular  operator +  (const Modular& other) const { Modular tmp = *this; return tmp += other; }
		template<class T> Modular& operator += (const T& other) { return *this += initModular(other); }
		template<class T> Modular  operator +  (const T& other) const { return *this +  initModular(other); }
		template<class T> friend Modular operator + (const T& other, const Modular& m) { return m.initModular(other) + m; }

		Modular& operator ++()    { return *this += 1; }
		Modular  operator ++(int) { Modular tmp = *this; ++*this; return tmp; }

		Modular  operator -  () const { return initModular(-val); }
		Modular& operator -= (const Modular& other) { validate(other); val -= other.val; val += MODVALUE; val %= MODVALUE; return *this;}
		Modular  operator -  (const Modular& other) const { Modular tmp = *this; return tmp -= other; }
		template<class T> Modular& operator -= (const T& other) { return *this -= initModular(other); }
		template<class T> Modular  operator -  (const T& other) const { return *this -  initModular(other); }
		template<class T> friend Modular operator - (const T& other, const Modular& m) { return m.initModular(other) - m; }

		Modular& operator --()    { return *this -= 1; }
		Modular  operator --(int) { Modular tmp = *this; --*this; return tmp; }

		Modular& operator *= (const Modular& other) { validate(other); val *= other.val; val %= MODVALUE; val += MODVALUE; val %= MODVALUE; return *this; }
		Modular  operator *  (const Modular& other) const { Modular tmp = *this; return tmp *= other; }
		template<class T> Modular& operator *= (const T& other) { return *this *= initModular(other); }
		template<class T> Modular  operator *  (const T& other) const { return *this *  initModular(other); }
		template<class T> friend Modular operator * (const T& other, const Modular& m) { return m.initModular(other) * m; }

		Modular pow(long long power) const {
			Modular m = *this, ans = initModular(1);
			while (power) {
				if (power & 1) ans *= m;
				m *= m;
				power >>= 1;
			}
			return ans;
		}
		Modular pow(const Modular& other) const { return pow(other.val); }
		Modular inv() const { return pow(MODVALUE - 2); }

		Modular& operator /= (const Modular& other) { val *= other.inv().val; val %= MODVALUE; return *this; }
		Modular  operator /  (const Modular& other) const { Modular tmp = *this; return tmp /= other; }
		template<class T> Modular& operator /= (const T& other) { return *this /= initModular(other); }
		template<class T> Modular  operator /  (const T& other) const { return *this /  initModular(other); }
		template<class T> friend Modular operator / (const T& other, const Modular& m) { return m.initModular(other) / m; }

		friend istream& operator >> (istream& in, Modular& m) { in >> m.val; m.val %= m.MODVALUE; m.val += m.MODVALUE; m.val %= m.MODVALUE; return in; }
		friend ostream& operator << (ostream& out, const Modular& m) { return out << m.val; }

		Modular() { val = 0; MODVALUE = 0; }
		Modular(long long val, long long MOD) : MODVALUE(MOD), val((val % MOD + MOD) % MOD) { }
	};
	using Mint = Modular;
	inline ll binpow(ll b, ll p, ll mod) {
		b %= mod;
		ll ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
	inline ll max(ll a, int b) { return (a > b ? a : b); }
	inline ll max(int a, ll b) { return (a > b ? a : b); }
	inline ll min(ll a, int b) { return (a < b ? a : b); }
	inline ll min(int a, ll b) { return (a < b ? a : b); }
	template <class T> inline bool chkmin(T&x, const T& y) { return x > y ? x = y, 1 : 0; }
	template <class T> inline bool chkmax(T&x, const T& y) { return x < y ? x = y, 1 : 0; }
}
namespace IO {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
	template<class T> inline void _R(deque<T> &x) {for (auto& i : x) _R(i);}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}

	template<class T> inline void _W(const T& x);
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p);
	template<class... T> inline void _W(const vector<T...>& x);
	template<class... T> inline void _W(const deque<T...>& x);
	template<class... T> inline void _W(const forward_list<T...>& x);
	template<class... T> inline void _W(const list<T...>& x);
	template<class... T> inline void _W(const set<T...>& x);
	template<class... T> inline void _W(const multiset<T...>& x);
	template<class... T> inline void _W(const unordered_set<T...>& x);
	template<class... T> inline void _W(const unordered_multiset<T...>& x);
	template<class... T> inline void _W(const map<T...>& x);
	template<class... T> inline void _W(const multimap<T...>& x);
	template<class... T> inline void _W(const unordered_map<T...>& x);
	template<class... T> inline void _W(const unordered_multimap<T...>& x);

	template<class Container> inline void printContainer(const Container& x) { bool isFirst = 1; for (auto i : x) { if (!isFirst) cout << ' '; isFirst = 0; _W(i); } }

	template<class T> inline void _W(const T& x) {cout << x;}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
	template<class... T> inline void _W(const vector<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const deque<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const forward_list<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const list<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const set<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const multiset<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const unordered_set<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const unordered_multiset<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const map<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const multimap<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const unordered_map<T...>& x) { printContainer(x); }
	template<class... T> inline void _W(const unordered_multimap<T...>& x) { printContainer(x); }

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace IO;
namespace outputFormat{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
	inline string YN(bool b) {return b ? "Yes" : "No";}
} using namespace outputFormat;
namespace std {
    template <class T1, class T2> struct hash<pair<T1,T2>> {
    	std::size_t operator()(pair<T1,T2> _) const {
        	return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
    	}
    };
}
const Mint ZERO = Mint(0, MOD998);

struct KMP {
	vector<int> next;
	string s;

	inline int match(string& t) {
		int ans = 0;
		for (int i = 0, j = -1; i < (int)t.length(); i++) {
			while (j >= 0 && s[j + 1] != t[i]) j = next[j];
			if (s[j + 1] == t[i]) j++;
			if (j == s.length()-1) {
				ans++;
				j = next[j];
			}
		}
		return ans;
	}

	inline KMP(string& s) : s(s) {
		next.resize(s.length());
		next[0] = -1;
		for (int i = 1; i < (int)s.length(); i++) {
			int j = next[i - 1];
			while (j >= 0 && s[j + 1] != s[i]) j = next[j];
			if (s[j + 1] == s[i]) j++;
			next[i] = j;
		}
	}
};

int main() {
	int n,q; R(n,q);
	vector<string> s(1); R(s[0]);
	string t; R(t);

	const unsigned int MAXL = 1000000;
	for (int i = 0; s.back().length() < MAXL; i++)
		s.emplace_back(s.back() + t[i] + s.back());

	const Mint TWO = Mint(2, MOD107);
	const Mint TWOinv = TWO.inv();

	vector<vector<Mint>> occv(26, vector<Mint>(n + 1, Mint(0, MOD107)));
	{
		Mint now = Mint(1, MOD107);
		for (int i = 1; i <= n; i++) {
			now *= TWOinv;
			occv[t[i - 1] - 'a'][i] += now;
		}

		for (int i = 0; i < 26; i++)
			for (int j = 1; j <= n; j++)
				occv[i][j] += occv[i][j - 1];
	}
	
	while (q--) {
		int k; R(k);
		string w; R(w);
		const int len = w.length();

		KMP kmp(w);

		int smin = 0;
		while (s[smin].length() < len) ++smin;

		if (smin > k) {
			W(0);
			continue;
		}

		int match = kmp.match(s[smin]);
		vector<Mint> occ(26, Mint(0, MOD107));
		vector<int> tmatch(26, 0);
		{
			Mint mul = TWO.pow(k);
			for (int i = 0; i < 26; i++)
				occ[i] = (occv[i][k] - occv[i][smin]) * mul;

			string toMatch = s[smin].substr(s[smin].length() - len + 1, len - 1) + '_' + s[smin].substr(0, len - 1);

			for (int i = 0; i < 26; i++) {
				toMatch[len - 1] = 'a' + i;
				tmatch[i] = kmp.match(toMatch);
			}
		}
		
		Mint ans = Mint(0, MOD107);
		ans += match * TWO.pow(k - smin);

		for (int i = 0; i < 26; i++)
			ans += tmatch[i] * occ[i];

		W(ans);
	}

	return 0;
}

static auto __init__ = [](){
#ifndef LOCAL
	ios::sync_with_stdio(false);
	// cin.tie(0);
#endif
	cout << fixed << setprecision(10);
	return 42;
}();