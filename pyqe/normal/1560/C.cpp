#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i*i<n;i++);
		n-=(i-1)*(i-1);
		printf("%lld %lld\n",min(n,i),i+1-max(n-i+1,1ll));
	}
}