#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=2;i<=n;i++)
		{
			if(abs(a[i]-a[i-1])>1)
			{
				printf("YES\n%lld %lld\n",i-1,i);
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("NO\n");
		}
	}
}