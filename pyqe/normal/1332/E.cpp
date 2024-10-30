#include <bits/stdc++.h>

using namespace std;

const long long mm=2;
long long n,m,lb,rb,fq[2],m0[mm][mm],m1[mm][mm],tmp[mm][mm],mz[mm][mm],a0[mm],az[mm],dv=998244353;

void cop(long long x[mm][mm],long long y[mm][mm])
{
	long long i,j;
	
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			y[i][j]=x[i][j];
		}
	}
}

void mul(long long x[mm][mm],long long y[mm][mm],long long z[mm][mm])
{
	long long i,j,r;
	
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			tmp[i][j]=0;
			for(r=0;r<mm;r++)
			{
				tmp[i][j]=(tmp[i][j]+x[i][r]*y[r][j])%dv;
			}
		}
	}
	cop(tmp,z);
}

void mpw(long long x)
{
	if(!x)
	{
		cop(m0,mz);
		return;
	}
	mpw(x/2);
	mul(mz,mz,mz);
	if(x%2)
	{
		mul(mz,m1,mz);
	}
}

int main()
{
	long long i,j,z;
	
	for(i=0;i<mm;i++)
	{
		m0[i][i]=1;
	}
	a0[0]=1;
	scanf("%lld%lld%lld%lld",&n,&m,&lb,&rb);
	fq[0]=rb/2-(lb-1)/2;
	fq[1]=(rb+1)/2-lb/2;
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			m1[i][j]=fq[i==j];
		}
	}
	mpw(n*m);
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			az[i]=(az[i]+a0[j]*mz[i][j])%dv;
		}
	}
	z=(az[0]+az[1]*(n*m%2))%dv;
	printf("%lld\n",z);
}