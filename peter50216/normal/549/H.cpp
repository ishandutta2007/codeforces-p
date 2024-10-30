// @author peter50216
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}

const double eps=0;
double v[4];
vector<double> px[4];
double mi,ma;
double vv[4];
inline void dfs(int np){
  if(np==4){
    double x=vv[0]*vv[3]-vv[1]*vv[2];
    mi=min(mi,x);
    ma=max(ma,x);
    return;
  }
  for(double p:px[np]){
    vv[np]=p;
    dfs(np+1);
  }
}
inline bool solve(double x){
  REP(i,4)px[i].clear();
  REP(i,4){
    px[i].push_back(v[i]-x);
    px[i].push_back(v[i]+x);
    if(v[i]-x<=0&&v[i]+x>=0)px[i].push_back(0);
  }
  mi=1e100;
  ma=-1e100;
  dfs(0);
  return mi<=eps&&ma>=-eps;
}
int main(){
  scanf("%lf%lf%lf%lf",&v[0],&v[1],&v[2],&v[3]);
  double l=0,r=1e12;
  REP(k,300){
    double m=(l+r)/2;
    if(solve(m))r=m;
    else l=m;
  }
  printf("%.10f\n",l);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread