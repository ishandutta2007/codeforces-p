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
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,k;
int a[MN],b[MN],v[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
void dfs(int u){v[u]=1;for(int i=h[u];i;i=nxt[i])if(!v[to[i]])dfs(to[i]);}
int main(){
	scanf("%d%d",&n,&m),k=n;
	F(i,1,m)scanf("%d%d",a+i,b+i),ins(a[i],b[i]),ins(b[i],a[i]);
	F(i,1,n)if(!v[i])--k,dfs(i);
	printf("%d\n",m-k);
	return 0;
}