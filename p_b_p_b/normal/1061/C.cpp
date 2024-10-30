#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 1010100
    typedef long long ll;
    typedef double db;
    const ll mod=1e9+7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    template<typename T>inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    template<typename T>inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
        t=(f?-t:t);
    }
    template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.txt","r",stdin);
        #endif
    }
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n;
vector<int>v;
ll dp[sz];

int main()
{
    file();
    read(n);
    int x;
    dp[0]=1;
    rep(i,1,n)
    {
        read(x);v.clear();
        for (int j=1;j*j<=x;j++) if (x%j==0)
        {
            v.push_back(j);
            if (j*j!=x) v.push_back(x/j);
        }
        sort(v.begin(),v.end());
        drep(j,(int)v.size()-1,0) 
            if ((x=v[j])<=n) 
                dp[x]=(dp[x]+dp[x-1])%mod;
    }
    ll ans=0;
    rep(i,1,n) (ans+=dp[i])%=mod;
    cout<<ans;
    return 0;
}