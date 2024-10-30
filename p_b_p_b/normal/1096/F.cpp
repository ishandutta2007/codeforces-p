#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    #define mod 998244353ll
    #define sz 200220 
    typedef long long ll;
    typedef double db;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
    templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
    templ inline void read(T& t)
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
        freopen("a.in","r",stdin);
        #endif
    }
    inline void chktime()
    {
        #ifndef ONLINE_JUDGE
        cout<<(clock()-t)/1000.0<<'\n';
        #endif
    }
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m;
int a[sz];
bool vis[sz];

ll tr[sz];
void add(int x,int y){while (x<=n) (tr[x]+=y)%=mod,x+=(x&(-x));}
int query(int x){ll ret=0;while (x) (ret+=tr[x])%=mod,x-=(x&(-x));return ret;}
ll fac[sz];

int main()
{
    file();
    cin>>n;
    rep(i,1,n)
    {
        cin>>a[i];
        if (a[i]==-1) ++m;
    }
    ll ans=0;
    rep(i,1,n) if (a[i]!=-1) (ans+=query(n)-query(a[i]))%=mod,add(a[i],1);
    fac[0]=1;rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    (ans*=fac[m])%=mod;
    (ans+=fac[m]*inv(4)%mod*(1ll*m*(m-1)%mod)%mod)%=mod;
    int cnt=0;
    rep(i,1,n)
        if (a[i]!=-1) (ans+=fac[m-1]*(1ll*cnt*(m+query(a[i])-a[i])%mod+1ll*(m-cnt)*(a[i]-query(a[i]))%mod)%mod)%=mod;
        else ++cnt;
    cout<<ans*inv(fac[cnt])%mod;
    return 0;
}