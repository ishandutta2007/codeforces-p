#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
ll ans;
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%d",a+i);
	ans=a[n]-a[1],--k;
	F(i,1,n-1)a[i]=a[i+1]-a[i];
	sort(a+1,a+n);
	F(i,1,k)ans-=a[n-i];
	printf("%lld\n",ans);
	return 0;
}