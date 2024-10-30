#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
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
	vector<pair<int, int>> a(n);
	vector<int> s;
	for (auto &it : a) cin >> it.first >> it.second, s.push_back(it.first), s.push_back(it.second);
	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());
	vector<int> p(2*n+1);
	for (auto &it : a) {
		it.first = lower_bound(s.begin(), s.end(), it.first) - s.begin();
		it.second = lower_bound(s.begin(), s.end(), it.second) - s.begin();
		p[it.first]++;
		p[it.second+1]--;
	}
	int mx = p[0];
	for (int i = 1; i <= 2*n; ++i) p[i] += p[i-1], mx = max(p[i], mx);
	cout << (mx <= 2 ? "YES" : "NO");


	return 0;
}