#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
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
int n;
int a[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){int ok=0;
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,2,n)if(abs(a[i-1]-a[i])>=2){printf("YES\n%d %d\n",i-1,i),ok=1;break;}
	if(!ok)puts("NO");
}	return 0;
}