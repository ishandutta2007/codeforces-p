#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

//(n - 1) + 2 * (n - 2) + 3 * (n-3) + ... + n

int main(){
    int n, a, b, c, d = 0;
    scanf("%d", &n);
    scanf("%d", &a);
    b = c = a;
    FWD(i,1,n){
        scanf("%d", &a);
        if(b < a){
            ++d;
            b = a;
        }
        if(c > a){
            ++d;
            c = a;
        }
    }
    printf("%d\n", d);
    return 0;
}