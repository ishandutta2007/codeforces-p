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

vii a;
set<pair<int,ii>> s;

int main()
{
    boost;
    int d,n,m;
    cin>>d>>n>>m;
    a.rz(m+2);

    a[0]={0,INF};

    FOR(i,1,m)
    cin>>a[i].F>>a[i].S;
    a[m+1]={d,INF};
    sort(all(a));
    
    int p1=a[1].F;
    ll ans=0;
    int hv=n-p1;
    if(hv<0){cout<<"-1";return 0;}

    s.insert(MP(a[1].S,MP(1,n-hv)));
    int off=0;
    int pos=0;
    
    FOR(i,2,m+1)
    {
        int need=a[i].F-a[i-1].F;
        if(hv>=need){hv-=need,need=0;s.insert({a[i].S,{i,n-hv}});continue;}
        else need-=hv,hv=0;
        // cout<<need<<" ";
        while(!s.empty()){
            if(need==0)break;
            int mn = s.begin()->F;
            int j= s.begin()->S.F;
            int x = s.begin()->S.S;
            s.erase(s.begin());
            if(x-off<=0)continue;
            if(j<pos)
                continue;
            pos=j;
            int can = x-off;
            
            if(can<0)continue;
            if(can>need)
            ans+=need*1LL*mn,off+=need,s.insert({a[j].S,{j,can-need+off}}),need=0;
            else
            ans+=can*1LL*mn,need-=can,off+=can;
        // cout<<ans<<" ";
        }
        if(need>0){cout<<"-1";return 0;}
        s.insert({a[i].S,{i,n+off}});    
    }
    cout<<ans<<"\n";
    return 0;
}

// 200001 100000 2
// 110000 2
// 50000 1