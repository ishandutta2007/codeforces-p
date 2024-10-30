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

int dp[3010];
int ai[3010],bi[3010],ci[3010];
int main(){
  DRI(n);
  REP1(i,1,n)RI(ai[i]);
  REP1(i,1,n)RI(bi[i]);
  REP1(i,1,n)RI(ci[i]);
  ci[1]=bi[1];bi[1]=ai[1];
  ci[n]=bi[n];bi[n]=ai[n];
  dp[0]=0;
  dp[1]=ci[1];
  REP1(i,2,n){
    dp[i]=0;
    int sumb=0,maxcb=-100000000;
    PER1(j,i,1){
      int cc=(j==1||j==i)?bi[j]:ai[j];
      int rc=sumb+maxcb;
  //    printf("i=%d j=%d %d %d\n",i,j,cc,rc);
      if(j<i)dp[i]=max(dp[i],dp[j-1]+cc+rc);
      sumb+=bi[j];
      maxcb=max(maxcb,ci[j]-bi[j]);
    }
    dp[i]=max(dp[i],sumb+maxcb);
  }
  PI(dp[n]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread