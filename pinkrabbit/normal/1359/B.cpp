#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
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
int n,m,x,y;
char a[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d%d",&n,&m,&x,&y),y=min(y,2*x);
	int ans=0;
	F(i,1,n){
		scanf("%s",a+1);
		a[m+1]='*';
		F(i,1,m){
			if(a[i]=='.'){
				a[i]='*';
				if(a[i+1]=='.')ans+=y,a[i+1]='*';
				else ans+=x;
			}
		}
	}
	printf("%d\n",ans);
}	return 0;
}