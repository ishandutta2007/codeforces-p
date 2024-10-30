#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int cnt(int x){
    int c = 0;
    while(x){
        if(x%10 == 7 || x%10 == 4)
            ++c;
        x /= 10;
    }
    return c;
}

int n, k, a, c;

int main(){
    c = 0;
    scanf("%d %d", &n, &k);
    FWD(i,0,n){
        scanf("%d", &a);
        if(cnt(a) <= k)
            ++c;
    }
    printf("%d\n", c);
    return 0;
}