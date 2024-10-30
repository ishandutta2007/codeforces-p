#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000363

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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


vvii g;
int to;
vi vis,viss;
vi anss,anss2,col;
vi tt;
int temp;
bool dfs(int i,int j){
    viss[i]=1;
    vis[i]=1;
    bool ans=1;
    temp+=j;
    col[i]=j;
    if(j)tt.pb(i);
    for(auto it:g[i]){
        if(vis[it.F])ans&=((it.S^j^col[it.F])==to);
        else ans&=dfs(it.F,it.S^j^to);
    }
    return ans;
}

void clean(int i)
{
    vis[i]=col[i]=0;
    for(auto it:g[i]){
        if(vis[it.F]==1)
            clean(it.F);
    }
}

int main()
{
    boost;
    int n,m;
    cin>>n>>m;
    g.rz(n);
    vis.rz(n);
    viss.rz(n);
    FOR(i,0,m-1){
        int x,y; char ch;
        cin>>x>>y>>ch;
        g[x-1].pb({y-1,ch=='R'});
        g[y-1].pb({x-1,ch=='R'});
    }
    
    col.rz(n);
    to=0;int ans=0,ans2=0;
    
    bool can=1;
    FOR(i,0,n-1){
        if(viss[i])continue;
        bool cann=0;
        int t=INF;
        vi ttt;
        if(dfs(i,0)){
            if(temp<t)t=temp,ttt.swap(tt);
            cann=1;
        }
        temp=0;
        tt.clear();
        clean(i);
        
        if(dfs(i,1)){
            if(temp<t)t=temp,ttt.swap(tt);
            cann=1;
        }
        temp=0;
        tt.clear();
        clean(i);
        can&=cann;
        ans+=t;
        for(auto it:ttt)anss.pb(it);
    }

    fill(all(viss),0);
    to=1;
    bool can2=1;
    FOR(i,0,n-1){
        if(viss[i])continue;
        int t=INF;
        bool cann=0;
        vi ttt;
        if(dfs(i,0)){
            if(temp<t)t=temp,ttt.swap(tt);
            cann=1;
        }
        temp=0;
        tt.clear();
        clean(i);
        
        if(dfs(i,1)){
            if(temp<t)t=temp,ttt.swap(tt);
            cann=1;
        }
        temp=0;
        tt.clear();
        clean(i);
        can2&=cann;
        ans2+=t;
        for(auto it:ttt)anss2.pb(it);
    }
    if(can and can2 and ans2<ans)swap(ans,ans2),anss.swap(anss2);
    if(can==false and can2)swap(ans,ans2),anss.swap(anss2),swap(can,can2);
    if(!can){cout<<"-1";return 0;}
    cout<<ans<<"\n";
    for(auto it:anss)cout<<it+1<<" ";

    return 0;
}