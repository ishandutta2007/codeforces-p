#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FOR(a,b,c) for(int a=(b); a<(c); ++a)
#define FORD(i,a,b) for (int i=((int)(a))-1; i>=(b); --i)
#define REP(a,b) for(int a=0; a<(b); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PDD pair<long double, long double>
#define x first
#define y second
#define EPS 1e-9
#define INF 1000000009

using namespace std;

int n, m, c;
char S[110][110];
char B[110];

inline bool test(int i){
    FWD(j,0,m)
        if(B[j] == S[i][j])
            return 1;
    return 0;
}

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n)
        scanf("%s", S[i]);
    FWD(i,0,n)
        FWD(j,0,m)
            B[j] = max(B[j], S[i][j]);
    FWD(i,0,n)
        c += test(i);
    printf("%d\n", c);
    return 0;
}