// By: Little09
// Problem: B. I love AAAB
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/B
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
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
char s[N];
void work()
{
	int sum=0;
	cin >> s+1;
	n=strlen(s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]-'A';
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0) sum++;
		else sum--;
		if (sum<0)
		{
			printNO;
			return;
		}
	}
	if (a[n]==0) printNO;
	else printYES;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}