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
#define pres(s,x) (s.find(x)!=s.end())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i, n) FOR (i, 0, (n) - 1)
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

const int N = 1001;
int n;
int a[N],s[N];
int dp1[10001];
int dp2[10001];


int f(int l, int r) {
	if (l == r) return 0;

	int mid = (l + r) >> 1;
	int ans = add(f(l, mid), f(mid + 1, r));

	int lmt = 0;
	FOR (i, l, r) lmt += a[i];
	lmt >>= 1;


	FOR (i, 0, lmt) dp1[i] = dp2[i] = 0;

	dp2[0] = 1;
	FOR (i, mid + 1, r) {
		NFOR (j, lmt, a[i]) {
			dp2[j] = add(dp2[j], dp2[j - a[i]]);
		}
		FOR (j, 0, lmt) {
			if (j <= ((s[i] - s[l - 1]) >> 1))
				dp1[j] = add(dp1[j], dp2[((s[i] - s[l - 1]) >> 1) - j]);
		}
	}


	FOR (i, 0, lmt) dp2[i] = 0;	

	dp2[0] = 1;
	NFOR (i, mid, l) {
		NFOR (j, lmt, a[i]) {			
			dp2[j] = add(dp2[j], dp2[j - a[i]]);
		}
		FOR (j, 0, lmt) {
			int yo = ((s[i - 1] - s[l - 1]) >> 1) + j;
			if(yo <= lmt)
				ans = add(ans, mul(dp2[j], dp1[yo]));
		}
	}
	return ans;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	FOR (i, 1, n) cin >> a[i], a[i] <<= 1, s[i] = s[i-1] + a[i];
	cout << f(1, n);

	return 0;	
}