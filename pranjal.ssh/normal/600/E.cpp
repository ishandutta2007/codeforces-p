#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}
vvi g;
vi c;
vi pos;
vector<map<int,int>> dp;
vll ans;
vector<pair<int,ll>> cnt;

void dfs(int u, int p=-1)
{
    
    tr(g[u],it)
    {
        if((*it)==p)continue;
        dfs(*it,u);
        
        if(dp[pos[u]].size()<dp[pos[*it]].size())
        swap(pos[u],pos[*it]);
        
        tr(dp[pos[*it]],itt)
        {
            dp[pos[u]][itt->F]+=itt->S;
            
            if(cnt[pos[u]].F==dp[pos[u]][itt->F])
            cnt[pos[u]].S+=itt->F;
            
            else if(dp[pos[u]][itt->F]>cnt[pos[u]].F)
            
            cnt[pos[u]]={dp[pos[u]][itt->F],itt->F};
        }
        
    }
    ans[u]=cnt[pos[u]].S;
}
int main()
{
    boost;
    int n;
    cin>>n;
    g.rz(n);
    cnt.rz(n);
    c.rz(n);
    dp.rz(n);
    pos.rz(n);
    ans.rz(n);
    
    FOR(i,0,n-1)cin>>c[i],dp[i][c[i]]=1,pos[i]=i,cnt[i]={1,c[i]};
    FOR(i,0,n-2)
    {
        int x,y;
        cin>>x>>y;
        g[x-1].pb(y-1);
        g[y-1].pb(x-1);
    }
    dfs(0);
    FOR(i,0,n-1)cout<<ans[i]<<" ";
    
    return 0;
}