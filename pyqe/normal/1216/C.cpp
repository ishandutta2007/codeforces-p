#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long y[3][2],x[3][2],i,ii;
	bool bad=0;
	
	for(i=0;i<3;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld%lld",&y[i][ii],&x[i][ii]);
		}
	}
	for(i=1;i<3;i++)
	{
		if(y[i][0]<=y[0][0]&&x[i][0]<=x[0][0]&&y[i][1]>=y[0][1]&&x[i][1]>=x[0][1])
		{
			bad=1;
			break;
		}
	}
	if(y[1][0]<=y[0][0]&&y[1][1]>=y[0][1]&&y[2][0]<=y[0][0]&&y[2][1]>=y[0][1])
	{
		if(x[1][0]<=x[0][0]&&x[2][0]<=x[1][1]&&x[0][1]<=x[2][1])
		{
			bad=1;
		}
		if(x[2][0]<=x[0][0]&&x[1][0]<=x[2][1]&&x[0][1]<=x[1][1])
		{
			bad=1;
		}
	}
	if(x[1][0]<=x[0][0]&&x[1][1]>=x[0][1]&&x[2][0]<=x[0][0]&&x[2][1]>=x[0][1])
	{
		if(y[1][0]<=y[0][0]&&y[2][0]<=y[1][1]&&y[0][1]<=y[2][1])
		{
			bad=1;
		}
		if(y[2][0]<=y[0][0]&&y[1][0]<=y[2][1]&&y[0][1]<=y[1][1])
		{
			bad=1;
		}
	}
	if(bad)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
}