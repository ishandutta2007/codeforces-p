#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pdi pair<db,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 402020
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

int n,L;
db l[sz],v[sz]; int m;
db rs[sz];
priority_queue<pdi>q;

int main()
{
	file();
	read(n,L);
	auto add=[&](int x,int y,db vv){if (x!=y) l[++m]=y-x,v[m]=vv;};
	int x,y; db vv; read(x,y,vv); add(0,x,0); add(x,y,vv);
	rep(i,2,n) read(x),add(y,x,0),read(y,vv),add(x,y,vv); add(y,L,0);
	db ans=0;
	rep(i,1,m)
	{
		db r=(v[i]<1e-3?1e9:l[i]/v[i]),l=::l[i]/(v[i]+2); rs[i]=r-l;
		db t=::l[i],k=v[i]+1;
		t-=l*k; ans+=l;
		q.push(MP(k,i));
		while (t)
		{
			pdi p=q.top(); q.pop(); int x=p.sec;
			if (rs[x]*p.fir<t) { t-=rs[x]*p.fir; ans+=rs[x]; continue; }
			rs[x]-=t/p.fir,ans+=t/p.fir; t=0; q.push(p);
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}