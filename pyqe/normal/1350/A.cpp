#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=2;n%i;i++);
		n+=i;
		n+=(d-1)*2;
		printf("%lld\n",n);
	}
}