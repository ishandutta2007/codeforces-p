#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, p;
double s;

int main(){
    scanf("%d", &n);
    s = 0;
    FWD(i,0,n){
        scanf("%d", &p);
        s += p;
    }
    printf("%lf\n", s / n);
    return 0;
}