#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		sm=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			z+=!k;
			k+=!k;
			sm+=k;
		}
		z+=!sm;
		printf("%lld\n",z);
	}
}