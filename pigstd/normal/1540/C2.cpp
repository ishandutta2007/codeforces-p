#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=1e9+7;
const int M=110;
int dp[M][M*M],n,d[M],c[M],s[M],sc[M],sum[M][M*M],xx=1;
map<int,int>f;

void solve(int x)
{
	if (f[x]){printf("%lld\n",f[x]);return;}
	s[1]=x;
	for (int i=2;i<=n;i++)s[i]=s[i-1]+d[i-1];
	for (int i=1;i<=n;i++)s[i]+=s[i-1];
	if (s[n]<=0){printf("%lld\n",xx);return;}
	int ff=0,ss=0;
	for (int i=1;i<=n;i++)
	{
		ss+=c[i];
		if (ss<s[i])ff=1;
	}
	if (ff){puts("0");return;}
	memset(dp,0,sizeof(dp)),memset(sum,0,sizeof(sum));
	dp[0][0]=1,sum[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=max(s[i],0ll);j<=sc[i];j++)
		{
			dp[i][j]=sum[i-1][min(j,sc[i-1])];
			if (j>c[i])
				dp[i][j]=(dp[i][j]-sum[i-1][min(sc[i-1],j-c[i]-1)]+Mod)%Mod;
			sum[i][j]=(sum[i][j-1]+dp[i][j])%Mod;
		}
	int ans=0;
	for (int i=max(s[n],0ll);i<=sc[n];i++)ans=(ans+dp[n][i])%Mod;
	cout<<(f[x]=ans)<<endl;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)sc[i]=c[i]=read(),sc[i]+=sc[i-1],xx=xx*(c[i]+1)%Mod;
	for (int i=1;i<n;i++)d[i]=read();
	WT{solve(read());}
	return 0;
}