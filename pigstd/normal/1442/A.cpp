#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
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

const int M=3e4+10;
int n,a[M];

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=2;i<=n;i++)
		{
			if (a[i]<a[i-1])
				a[1]-=a[i-1]-a[i];
		}if (a[1]<0)NO
		else YES
	}
	return 0;
}