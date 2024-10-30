// Author: Little09
// Problem: A. Color the Picture
// Contest: Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,k; 
ll a[N],b[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

void work()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=k;i++) a[i]=read();
	ll u=0,fl=0;
	for (int i=1;i<=k;i++)
	{
		if (a[i]>=2*n)
		{
			u+=a[i]/n;
			if (a[i]>=3*n) fl=1;
		}
	}
	if (u==m||(u>m&&(m%2==0||fl==1)))
	{
		printYes;
		return;
	}
	u=0,fl=0;
	for (int i=1;i<=k;i++)
	{
		if (a[i]>=2*m)
		{
			u+=a[i]/m;
			if (a[i]>=3*m) fl=1;
		}
	}
	if (u==n||(u>n&&(n%2==0||fl==1)))
	{
		printYes;
		return;
	}
	printNo;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}