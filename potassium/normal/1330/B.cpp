#pragma GCC optimize ("O3", "unroll-loops")
//#pragma GCC target ("avx2")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
namespace {
	const int MOD = 1000000007;
	const int MOD2 =  998244353;
	const int INF = 2147483647;
	const long long LLINF = LLONG_MAX;
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int,int> pii;
	typedef pair<ll,ll> pll;
	template <class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
	template <class T> using maxheap = priority_queue<T, vector<T>, greater<T>>;
	template <int MODVALUE>
	struct Modular {
	private:
		long long val;

		template<class T>
		static Modular toModular(const T& m) {
			long long val = m;
			if (val < 0) val += MODVALUE;
			if (val >= MODVALUE) val -= MODVALUE;
			return Modular(val);
		}

	public:
		bool operator == (const Modular& other) {return val == other.val;}
		bool operator != (const Modular& other) {return !(val == other.val);}
		template<class T> bool operator == (const T& other) {return *this == Modular(other);}
		template<class T> bool operator != (const T& other) {return !(*this == Modular(other));}
		template<class T> friend bool operator == (const T& other, const Modular& m) {return Modular(other) == m;}
		template<class T> friend bool operator != (const T& other, const Modular& m) {return !(Modular(other) == m);}

		bool operator < (const Modular& other) {return val < other.val;}
		bool operator <= (const Modular& other) {return val <= other.val;}
		bool operator > (const Modular& other) {return val > other.val;}
		bool operator >= (const Modular& other) {return val >= other.val;}
		template<class T> bool operator < (const T& other) {return *this < Modular(other);}
		template<class T> bool operator <= (const T& other) {return *this <= Modular(other);}
		template<class T> bool operator > (const T& other) {return *this > Modular(other);}
		template<class T> bool operator >= (const T& other) {return *this >= Modular(other);}
		template<class T> friend bool operator < (const T& other, const Modular& m) {return Modular(other) < m;}
		template<class T> friend bool operator <= (const T& other, const Modular& m) {return Modular(other) <= m;}
		template<class T> friend bool operator > (const T& other, const Modular& m) {return Modular(other) > m;}
		template<class T> friend bool operator >= (const T& other, const Modular& m) {return Modular(other) >= m;}

		Modular operator + (const Modular& other) {return toModular(val + other.val);}
		Modular& operator += (const Modular& other) {return *this = *this + other;}
		template<class T> Modular operator + (const T& other) {return *this + Modular(other);}
		template<class T> Modular& operator += (const T& other) {return *this += Modular(other);}
		template<class T> friend Modular operator + (const T& other, const Modular& m) {return Modular(other) + m;}
		template<class T> friend Modular operator += (const T& other, const Modular& m) {return Modular(other) += m;}

		Modular& operator ++() {return *this += 1;}
		Modular operator ++(int) {Modular tmp = *this; ++*this; return tmp;}

		Modular operator - () const {return Modular(-val);}
		Modular operator - (const Modular& other) {return toModular(val - other.val);}
		Modular& operator -= (const Modular& other) {return *this = *this - other;}
		template<class T> Modular operator - (const T& other) {return *this - Modular(other);}
		template<class T> Modular& operator -= (const T& other) {return *this -= Modular(other);}
		template<class T> friend Modular operator - (const T& other, const Modular& m) {return Modular(other) - m;}
		template<class T> friend Modular operator -= (const T& other, const Modular& m) {return Modular(other) -= m;}

		Modular& operator --() {return *this -= 1;}
		Modular operator --(int) {Modular tmp = *this; --*this; return tmp;}

		Modular operator * (const Modular& other) {return toModular(val * other.val % MODVALUE);}
		Modular& operator *= (const Modular& other) {return *this = *this * other;}
		template<class T> Modular operator * (const T& other) {return *this * Modular(other);}
		template<class T> Modular operator *= (const T& other) {return *this *= Modular(other);}
		template<class T> friend Modular operator * (const T& other, const Modular& m) {return Modular(other) * m;}
		template<class T> friend Modular operator *= (const T& other, const Modular& m) {return Modular(other) *= m;}

		Modular pow(long long power) {
			Modular m = *this, ans = 1;
			while (power) {
				if (power & 1) ans *= m;
				m *= m;
				power >>= 1;
			}
			return ans;
		}
		Modular pow(const Modular& other) {return pow(other.val);}
		Modular inv() {return pow(MODVALUE-2);}

		Modular operator / (const Modular& other) {return *this * other;}
		Modular operator /= (const Modular& other) {return *this = *this / other;}
		template<class T> Modular operator / (const T& other) {return *this / Modular(other);}
		template<class T> Modular operator /= (const T& other) {return *this /= Modular(other);}
		template<class T> friend Modular operator / (const T& other, const Modular& m) {return Modular(other) / m;}
		template<class T> friend Modular operator /= (const T& other, const Modular& m) {return Modular(other) /= m;}

		friend istream& operator >> (istream& in, Modular& m) {in >> m.val; m = toModular(m.val % MODVALUE); return in;}
		friend ostream& operator << (ostream& out, const Modular& m) {return out << m.val;}

		Modular() : val(0) {}
		Modular(int val) : val(val % MODVALUE) {};
		Modular(long long val) : val(val % MODVALUE) {};
	};
	inline ll pow(ll b, ll p, ll mod) {
		b %= mod;
		ll ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
	inline ll max(ll a, int b) {return (a > b ? a : b);}
	inline ll max(int a, ll b) {return (a > b ? a : b);}
	inline ll min(ll a, int b) {return (a < b ? a : b);}
	inline ll min(int a, ll b) {return (a < b ? a : b);}
	inline bool chkmin(ll& x, ll y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(ll& x, int y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(int& x, ll y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(int& x, int y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmax(ll& x, ll y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(ll& x, int y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(int& x, ll y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(int& x, int y) {return x < y ? x = y, 1 : 0;}
}
namespace input {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
	template<class T> inline void _R(deque<T> &x) {for (auto& i : x) _R(i);}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
} using namespace input;
namespace output {
	template<class T> inline void _W(const T& x);
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p);
	template<class T> inline void _W(const vector<T>& x);
	template<class T> inline void _W(const deque<T>& x);
	template<class T> inline void _W(const forward_list<T>& x);
	template<class T> inline void _W(const list<T>& x);
	template<class T1, class T2, class T3> inline void _W(const set<T1,T2,T3>& x);
	template<class T> inline void _W(const multiset<T>& x);
	template<class T> inline void _W(const unordered_set<T>& x);
	template<class T> inline void _W(const unordered_multiset<T>& x);
	template<class T1, class T2, class T3> inline void _W(const map<T1, T2, T3>& x);
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x);
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x);
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x);

	template<class T> inline void _W(const T& x) {cout << x;}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
	template<class T> inline void _W(const vector<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const deque<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const forward_list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2, class T3> inline void _W(const set<T1,T2,T3>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const unordered_set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const unordered_multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2, class T3> inline void _W(const map<T1, T2, T3>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}

	template<class T> inline void _W(const ordered_set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace output;
namespace output_format{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
	inline string YN(bool b) {return b ? "YES" : "NO";}
} using namespace output_format;
namespace std {
    template <class T1, class T2> struct hash<pair<T1,T2>> {
    	std::size_t operator()(pair<T1,T2> _) const {
        	return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
    	}
    };
}
using Mint = Modular<MOD>;


int main() {
	CASE(t) {
		int n; R(n);
		vector<int> a(n); R(a);
		
		vector<bool> pre(n, 0), suf(n, 0);
		int mx = 0;
		vector<int> cnt(n, 0);
		int mxc = 0;
		for (int i = 0; i < n; i++) {
			chkmax(mx, a[i]);
			chkmax(mxc, ++cnt[a[i]]);
			if (mx == i + 1 && mxc == 1)
				pre[i] = 1;
		}
		
		mx = 0;
		cnt = vector<int>(n, 0);
		mxc = 0;
		for (int i = n-1; i >= 0; i--) {
			chkmax(mx,a[i]);
			chkmax(mxc, ++cnt[a[i]]);
			if (mx == n - i && mxc == 1)
				suf[i] = 1;
		}
		
		vector<pii> ans;
		for (int i = 0; i < n-1; i++)
			if (pre[i] && suf[i+1])
				ans.pb(mp(i+1, n-i-1));
				
		W(ans.size());
		for (auto& i : ans)
			W(i);
	}
	
	return 0;
}

static auto _batch_ios = [](){
	#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);
	return 42;
}();