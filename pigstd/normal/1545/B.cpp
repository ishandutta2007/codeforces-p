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

const int Mod=998244353;
const int M=1e5+10;
int fac[M],ifac[M];
int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}
int inv(int x){return poww(x,Mod-2);}
void init(int n)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%Mod,
		ifac[i]=inv(fac[i]);
}
int C(int m,int n){return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;}

signed main()
{
	init(1e5);
	WT
	{
		int n=read();
		string s;cin>>s;
		int cnt1=0,cnt2=0,sum=0;
		for (int i=0;i<n;i++)
			if (s[i]=='0')cnt1+=sum/2,sum=0,cnt2++;
			else sum++;
		cnt1+=sum/2;
		cout<<C(cnt1+cnt2,cnt2)<<endl;
	}
	return 0;
}