#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;

template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

#define TRACE

#ifdef TRACE

#define cerr cout

#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#undef cerr
#else
#define pr(...)
#define pra(a,n)
#define praa(a,n,m)
#endif

#define inc_stack_limit const rlim_t kStackSize = 64 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;

const ll inf2 = 1e18;
const int inf = 1e9 + 7;

inline int add(int a, int b, int m = inf) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = inf) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}

const int N = 1e5 + 1;
int a[N];

template <typename node>
struct ST {

  #define mid ((l+r)>>1)

  int n;
  vector<node> T;

  ST(int n): n(n), T(4 * n + 10) {}

  void build(int no, int l, int r) {
    if (l == r) {FOR (i, 0, 59) T[no].t[i] = 1 + !(i % a[l]); return;}
    build(no << 1, l, mid);
    build(no << 1 | 1, mid + 1, r);
    T[no] = node::merge(T[no << 1], T[no << 1 | 1]);
  }
  
  void upd(int no, int l, int r, int pos) {
    if (l == r) {FOR (i, 0, 59) T[no].t[i] = 1 + !(i % a[l]); return;}
    if (pos <= mid) upd(no << 1, l, mid, pos);
    else upd(no << 1 | 1, mid + 1, r, pos);

    T[no] = node::merge(T[no << 1], T[no << 1 | 1]);
  }

  node qry(int no, int l, int r, int u, int v) {
    if (l >= u and r <= v)return T[no];
    if (v <= mid) {return qry(no << 1, l, mid, u, v);}
    else if (u >= mid + 1) {return qry(no << 1 | 1, mid + 1, r, u, v);}

    return node::merge(qry(no << 1, l, mid, u, v), qry(no << 1 | 1, mid + 1, r, u, v));
  }

};

struct node {
  int t[60];
  node() {}
  static node merge(const node&x, const node&y) {
  	node ans;
  	FOR (i, 0, 59) {
  		ans.t[i] = x.t[i] + y.t[(i + x.t[i]) % 60];
  	}
  	return ans;
  }
};

int main() 
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n; cin >> n; FOR (i, 1, n) cin >> a[i];

	ST<node> T(n);
	T.build(1, 1, n);

	TCASE {
		char ch;int x, y; cin >> ch >> x >> y;
		if (ch == 'A') {
			cout << T.qry(1, 1, n, x, y - 1).t[0] << "\n";
		}
		else {
			a[x] = y;
			T.upd(1, 1, n, x);
		}
	}

	return 0;	
}