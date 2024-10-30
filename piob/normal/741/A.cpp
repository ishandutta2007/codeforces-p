#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
int P[110];
int C[110];

int cycle(int u){
	int v = u;
	int c = 0;
	do {
		++c;
		v = P[v];
	}while(v != u);
	return c;
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d", &P[i]);
		--P[i];
		++C[P[i]];
	}
	bool good = 1;
	FWD(i,0,n) if(C[i] != 1) good = 0;
	if(!good){
		printf("-1\n");
		return 0;
	}
	LL r = 1;
	FWD(i,0,n){
		int c = cycle(i);
		r = r / gcd(r, (LL)c) * c;
	}
	printf("%lld\n", r / gcd(r, 2LL));
	return 0;
}