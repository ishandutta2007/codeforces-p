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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	string a, b; cin >> a >> b;
	int f[2][2]; memset(f, 0, sizeof f);
	FOR (i, 0, n - 1) {
		f[a[i]-'0'][b[i]-'0']++;
	}
	ll ans = 0;
	FOR (i, 0, 1) {
		FOR (j, 0, 1) {
			FOR (k, 0, 1) {
				FOR (l, 0, 1) {
					if (vi({(i|j), (k|l)}) != vi({(k|j), (i|l)})) {
						ans += f[i][j] * 1LL * f[k][l];
					}
				}
			}
		}
	}
	cout << ans / 2;

	return 0;
}