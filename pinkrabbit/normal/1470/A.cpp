#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,k[MN],c[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",k+i);
	F(i,1,m)scanf("%d",c+i);
	sort(k+1,k+n+1);
//	F(i,1,n)printf("%d%c",k[i]," \n"[i==n]);
//	F(i,1,m)printf("%d%c",c[i]," \n"[i==m]);
	ll ans=infll,sum=0;
	F(i,1,n)sum+=c[k[i]];
	int pos=1;
	dF(i,n,1){
		pos=max(pos,i-k[i]+1);
		if(i<pos)break;
		sum-=c[k[i]];
		sum+=c[n-i+1];
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}	return 0;
}