#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int MAXN = 100010;
const int MAXV = 2000010;

int n, k;

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n)
		FWD(j,0,n)
			printf("%d ", (i==j)*k);
	return 0;
}