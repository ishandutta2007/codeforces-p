#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,h,a[M],sum,ans,minn;

signed main()
{
	h=read(),n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),sum+=a[i],minn=min(minn,sum);
	if (h+minn>0&&sum>=0)return puts("-1"),0;
	if (h+minn<=0)
	{
		for (int i=1;i<=n;i++)
		{
			h+=a[i],ans++;
			if (h<=0)break;
		}
		cout<<ans<<endl;return 0;
	}
	int pp=(h+minn-1)/abs(sum)+1;
	h+=sum*pp;ans=pp*n;
	for (int i=1;i<=n;i++)
	{
		h+=a[i],ans++;
		if (h<=0)break;
	}cout<<ans<<endl;
	return 0;
}