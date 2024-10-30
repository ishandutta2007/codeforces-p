#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int ptr=0;
    string s;
    getline(cin,s);
    for (;ptr<s.size();++ptr){
        if (s[ptr]=='.')
            printf("0");
        else {
            ++ptr;
            if (s[ptr]=='.')
                printf("1");
            else
                printf("2");
        }
    }
    printf("\n");
  return 0;
}