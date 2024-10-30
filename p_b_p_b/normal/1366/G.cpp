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
	#define sz 10101
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
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m;
char s[sz],t[sz];

int del[sz],pr[sz];
stack<int>st;

int ans;
int dp[sz][sz];

int main()
{
	file();
	cin>>(s+1)>>(t+1);
	n=strlen(s+1),m=strlen(t+1);
	rep(i,1,n)
		if (s[i]!='.') st.push(i);
		else if (st.size()) del[st.top()]=1,pr[st.top()]=i,st.pop();
		else ++ans;
	memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
	rep(i,1,n) rep(j,0,m) if (dp[i-1][j]<=n)
	{
		if (s[i]=='.') chkmin(dp[i][j],dp[i-1][j]);
		else if (!del[i])
		{
			chkmin(dp[i][j],dp[i-1][j]+1);
			if (s[i]==t[j+1]) chkmin(dp[i][j+1],dp[i-1][j]);
		}
		else
		{
			chkmin(dp[pr[i]][j],dp[i-1][j]);
			chkmin(dp[i][j],dp[i-1][j]+2);
			if (s[i]==t[j+1]) chkmin(dp[i][j+1],dp[i-1][j]+1);
		}
	}
	cout<<ans+dp[n][m];
	return 0;
}