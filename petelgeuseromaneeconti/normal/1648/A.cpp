#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
int n,m;
vector<pair<int,int> >v[100005];
int main(){
	rd(n),rd(m);
	rep(i,1,n)rep(j,1,m){
		int c;
		rd(c);
		v[c].eb(i,j);
	}
	LL ans=0;
	rep(c,1,100000){
		sort(v[c].begin(),v[c].end());
		rep(i,0,SZ(v[c])-1){
			ans+=1LL*v[c][i].first*(i-(SZ(v[c])-1-i));
		}
		sort(v[c].begin(),v[c].end(),[&](pair<int,int>x,pair<int,int>y){return x.second<y.second;});
		rep(i,0,SZ(v[c])-1){
			ans+=1LL*v[c][i].second*(i-(SZ(v[c])-1-i));
		}
	}
	printf("%lld\n",ans);
	return 0;
}