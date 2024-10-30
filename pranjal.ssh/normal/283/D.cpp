#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	int ea[n]; memset(ea, 0, sizeof ea);
	ll a[n]; FOR (i, 0, n - 1) {
		cin >> a[i];
		while (!(a[i] & 1)) a[i] >>= 1, ++ea[i];
	}

	int dp[n];
	int ans = 1;
	FOR (i, 0, n - 1) {
		dp[i] = 1;
		FOR (j, 0, i - 1) {
			if (a[j] % a[i] == 0 and (ea[i] - (i - j) <= -1 or ea[j] == ea[i] - (i - j)))
				dp[i] = max(dp[i], 1 + dp[j]);
		}
		ans = max(ans, dp[i]);
	}
	cout << n - ans << "\n";

	return 0;
}