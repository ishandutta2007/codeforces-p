#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
int a[N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
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

void work()
{
	n=read();
	m=0;
	for (int i=1;i<=n;i++) a[i]=read(),m+=a[i];
	if (m>=n) printf("%d\n",m-n);
	else printf("1\n");
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}