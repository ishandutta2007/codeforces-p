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
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int f=(a+b)&1;
	int k=a+d==0?1:b+c==0?2:3;
	printf(f&&k&2?"Ya ":"Tidak ");
	printf(f&&k&1?"Ya ":"Tidak ");
	printf(!f&&k&1?"Ya ":"Tidak ");
	printf(!f&&k&2?"Ya\n":"Tidak\n");
}	return 0;
}