// By: Little09
// Problem: B. Reverse Sort
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.ml/contest/1605/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,T; 
int a[N];

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
int ans[N],cnt;
void work()
{
	n=read();
	int tot=0;
	cnt=0;
	for (int i=1;i<=n;i++) a[i]=readchar()-'0';
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0) tot++;
	}
	for (int i=1;i<=tot;i++)
	{
		if (a[i]==1) ans[++cnt]=i;
	}
	for (int i=tot+1;i<=n;i++)
	{
		if (a[i]==0) ans[++cnt]=i;
	}
	if (cnt==0) puts("0");
	else
	{
		puts("1");
		printf("%d ",cnt);
		for (int i=1;i<=cnt;i++) printf("%d ",ans[i]);
		puts("");
	}
	return;
}

int main()
{
	int tp=0;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
	}
	return 0;
}