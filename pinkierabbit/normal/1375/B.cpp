#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 305
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q,k;
int a[MN][MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,1,n)F(j,1,m)scanf("%d",&a[i][j]);
	int ok=1;
	F(i,1,n)F(j,1,m){
		int e=4;
		if(i==1)--e;
		if(i==n)--e;
		if(j==1)--e;
		if(j==m)--e;
		if(a[i][j]>e)ok=0;
	}
	if(!ok)puts("NO");
	else {
		puts("YES");
		F(i,1,n){F(j,1,m){
			int e=4;
			if(i==1)--e;
			if(i==n)--e;
			if(j==1)--e;
			if(j==m)--e;
			printf("%d ",e);
		}puts("");}
	}
}	return 0;
}