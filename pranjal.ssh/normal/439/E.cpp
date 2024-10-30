#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define ass(n,l,r) assert(n>=l and n<=r)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
const int N = 1e5;
int sv[N+1];
int inv[N+1];
int fac[N+1];
int mu[N+1];
int ifac[N+1];
vi divs[N+1];
inline int C(int n,int k){
  if(k>n)return 0;
  return mul(fac[n],mul(ifac[k],ifac[n-k]));
}
int main()
{
  fac[0]=1;inv[1]=1;ifac[0]=1;mu[1]=1;
  FOR(i,1,N){
    for(int j=i;j<=N;j+=i)
      divs[j].pb(i);
  }
  FOR(i,1,N)sv[i]=i;

  FOR(i,2,316)if(sv[i]==i)
  for(int j=i*i;j<=N;j+=i)sv[j]=i;
  FOR(i,2,N){int x = sv[i];if((i/x)%x==0)mu[i]=0;else mu[i]=-1*mu[i/sv[i]];}
  FOR(i,1,N)fac[i]=mul(i,fac[i-1]);
  FOR(i,2,N)inv[i]=INF-((INF/i)*1LL*inv[INF%i])%INF;
  FOR(i,1,N)ifac[i]=mul(inv[i],ifac[i-1]);
  
  boost;
  TCASE{
    int n,f;cin>>n>>f;
    if(n==1 and f==1){cout<<"1\n";continue;}
    int ans=0;
    for(auto it:divs[n]){
      if(mu[it]==-1)
        ans=add(ans,INF-C(n/it-1,f-1));
      else if(mu[it]==1)
        ans=add(ans,C(n/it-1,f-1));
    }
    cout<<ans<<"\n";
  }
  return 0;
}