#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353,inf=1<<30;
// head
const int N=2e5+5;

int n,m,k;
int cnt[N];

bool work(int n,int m) {
	ll cc=0;
	bool alltwo=true;
	rep(i,0,k) {
		int x=cnt[i]/n;
		if (x>1) cc+=x;
		if (x>2) alltwo=false;
	}
	if (m%2 && alltwo) return false;
	return cc>=m;
}

void solve() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,k) scanf("%d",&cnt[i]);

	if (work(n,m)||work(m,n)) puts("Yes");
	else puts("No");	
}


int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}