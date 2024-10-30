#include<bits/stdc++.h>
clock_t __t=clock();
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
	#define sz 605005
	typedef long long ll;
	typedef unsigned long long ull;
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
	inline void print(register int x)
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
		cout<<(clock()-__t)/1000.0<<'\n';
		#endif
	}
	ll ksm(ll x,int y,ll mod){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
}
using namespace my_std;

int n;

char s[sz];
bitset<sz>dp[1011];

const int mod=7000007,bs=37;
int h[sz];

bitset<7000007>b;
//int b[7000007];


int main()
{
	file();
	read(n);cin>>(s+1);
	chktime();
	int mx=0;while (1ll*mx*(mx+1)/2<=n) ++mx;
	rep(i,1,n) dp[1][i]=1,h[i]=s[i]-'a'+1;
	int ans=1,sum=0;
	rep(l,1,mx)
	{
		sum+=l;
		
		drep(i,n-sum-l+1,1)
		{
			int w=h[i];
			if (b[w]) dp[l+1][i]=1;
			int j=i+l;
			if (dp[l][j]) b[h[j]]=1;
			if (i!=1&&b[w]) dp[l+1][i-1]=1;
		}
		
		if (!dp[l+1].none()) ans=l+1;
		if (ans!=l+1) break;
		
		b.reset();
		rep(i,1,n-sum+3) h[i]=(h[i]*bs+s[i+l]-'a'+1)%mod;
	}
	chktime();
	cout<<ans;
	return 0;
}