// ka ni ma de chang
#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
ll c[500010],S[500010];
int set[500010],to[500010];
std::vector<int>G[500010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int qwq=gi();
	while(qwq--){
		int n=gi(),m=gi(),u,v;
		for(int i=1;i<=n;++i)G[i].clear(),c[i]=gi();
		for(int i=1;i<=m;++i)u=gi(),v=gi(),G[u].push_back(v);
		ll ans=0;
		int o=1;for(int i=1;i<=n;++i)set[i]=1;
		for(int i=1;i<=n;++i){
			std::vector<int>v;
			for(int j:G[i])if(!to[set[j]])to[set[j]]=++o;
			for(int j:G[i])v.push_back(set[j]),set[j]=to[set[j]];
			for(int j:v)to[j]=0;
		}
		for(int i=1;i<=o;++i)S[i]=0;
		for(int i=1;i<=n;++i)S[set[i]]+=c[i];
		for(int i=2;i<=o;++i)ans=std::__gcd(ans,S[i]);
		printf("%lld\n",ans);
	}
	return 0;
}