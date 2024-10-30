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
int val[200010];
int ord[200010];
int fin[200010];

bool cmp(int a, int b){
	return val[a] < val[b];
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &val[i]);
	FWD(i,0,n) val[i] += i;
	FWD(i,0,n) ord[i] = i;
	sort(ord, ord+n, cmp);
	FWD(i,0,n){
		//printf("na pozycje %d przyjedzie %d\n", i, ord[i]);
		fin[i] = val[ord[i]] - i;
	}
	bool ok = 1;
	FWD(i,0,n-1) if(fin[i] > fin[i+1]) ok = 0;
	if(ok){
		FWD(i,0,n) printf("%d ", fin[i]);
		printf("\n");
	}else
		printf(":(\n");
	return 0;
}