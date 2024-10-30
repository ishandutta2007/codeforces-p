#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 222
	#define mod 1000000007ll
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
	templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
	templ inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	char __sr[1<<21],__z[20];int __C=-1,__zz=0;
	inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
	inline void print(int x)
	{
		if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
		while(__z[++__zz]=x%10+48,x/=10);
		while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
	}
	void file()
	{
		#ifdef NTFOrz
		freopen("a.in","r",stdin);
		#endif
	}
	inline void chktime()
	{
		#ifdef NTFOrz
		cerr<<clock()/1000.0<<'\n';
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n;
vector<int>V[sz];
ll f[sz][sz];

int fa[sz],dep[sz],siz[sz];
void dfs(int x,int f)
{
	fa[x]=f,dep[x]=dep[f]+1,siz[x]=1;
	for (auto v:V[x]) if (v!=f) dfs(v,x),siz[x]+=siz[v];
}

int main()
{
	file();
	read(n);
	int x,y;
	rep(i,1,n-1) read(x,y),V[x].push_back(y),V[y].push_back(x);
	rep(i,1,n) f[0][i]=1;
	rep(i,1,n) rep(j,1,n) f[i][j]=(f[i-1][j]+f[i][j-1])*inv(2)%mod;
	ll ans=0;
	rep(i,1,n)
	{
		dfs(i,0);
		rep(j,1,i-1)
		{
			for (int x=fa[j],y=j;x;y=x,x=fa[x])
			{
				(ans+=(siz[x]-siz[y])*f[dep[x]-1][dep[j]-dep[x]]%mod)%=mod;
			}
		}
	}
	ans=ans*inv(n)%mod;
	cout<<ans;
	return 0;
}