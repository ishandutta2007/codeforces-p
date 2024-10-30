#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << ' '
#define EL << '\n'
#define WSP cout << ' '
#define WEL cout << '\n'
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
using namespace std;
template <class T1, class T2> inline ostream& operator << (ostream& out, pair<T1,T2>& p) {return out << p.first << ',' << p.second;}
template<class T> inline ostream& operator << (ostream& out, vector<T>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T> inline ostream& operator << (ostream& out, deque<T>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T> inline ostream& operator << (ostream& out, forward_list<T>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T> inline ostream& operator << (ostream& out, list<T>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T> inline ostream& operator << (ostream& out, set<T>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T> inline ostream& operator << (ostream& out, multiset<T>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T> inline ostream& operator << (ostream& out, unordered_set<T>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T> inline ostream& operator << (ostream& out, unordered_multiset<T>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T1, class T2> inline ostream& operator << (ostream& out, map<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T1, class T2> inline ostream& operator << (ostream& out, multimap<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T1, class T2> inline ostream& operator << (ostream& out, unordered_map<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
template<class T1, class T2> inline ostream& operator << (ostream& out, unordered_multimap<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
template <class T1, class T2> inline void _W(const pair<T1,T2>& p) {cout << p.first << ',' << p.second;}
template<class T> inline void _W(const vector<T>& x) {for (auto i : x) cout << i << ' ';}
template<class T> inline void _W(const deque<T>& x) {for (auto i : x) cout << i << ' ';}
template<class T> inline void _W(const forward_list<T>& x) {for (auto i : x) cout << i << ' ';}
template<class T> inline void _W(const list<T>& x) {for (auto i : x) cout << i << ' ';}
template<class T> inline void _W(const set<T>& x) {for (auto i : x) cout << i << ' ';}
template<class T> inline void _W(const multiset<T>& x) {for (auto i : x) cout << i << ' ';}
template<class T> inline void _W(const unordered_set<T>& x) {for (auto i : x) cout << i << ' ';}
template<class T> inline void _W(const unordered_multiset<T>& x) {for (auto i : x) cout << i << ' ';}
template<class T1, class T2> inline void _W(const map<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
template<class T> inline void _R(T& x) {cin >> x;}
inline void R() {}
template <class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
template<class T> inline void _W(T& x) {cout << x << ' ';}
inline void W() {}
template <class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); W(y...);}

int main() {
	int n; R(n);
	int cnt[3] = {0,0,0};
	for (int i = 0; i < n; i++) {
		int x; R(x);
		cnt[x]++;
	}
	if (cnt[1] && cnt[2]) {
		W(2); W(1);
		cnt[2]--; cnt[1]--;
	}
	while (cnt[2]--) W(2);
	while (cnt[1]--) W(1);
	
	return 0;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();