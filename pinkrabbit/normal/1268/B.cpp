#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;ll ans;
int a[MN],b[MN],f[MN],g[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n),ans=0;
	F(i,1,n)scanf("%d",a+i),ans+=a[i]/2,a[i]%=2;
	int x=0,y=0;
	F(i,1,n)(i&1?x:y)+=a[i];
	printf("%lld\n",ans+min(x,y));
}	return 0;
}