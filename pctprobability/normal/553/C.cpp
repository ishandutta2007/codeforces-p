#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = long long;
#define all(s) (s).begin(),(s).end()
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
//#define P pair<ll,ll>
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

void gbjsmzmfuuvdf(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(20);
}
vector<pair<ll,ll>> g[200000];
ll tmp[200000];
ll ans=mod/2+1;
void dfs(ll a,ll b){
  if(tmp[a]!=-1){
    if(tmp[a]!=b){
      ans=0;
      return;
    }
    return;
  }
  tmp[a]=b;
  for(auto h:g[a]){
    dfs(h.fi,(b+h.se)%2);
  }
}
    
int main() {
  gbjsmzmfuuvdf();
  ll a,b;
  cin>>a>>b;
  map<pair<ll,ll>,ll> m;
  for(int i=0;i<a;i++){
    tmp[i]=-1;
  }
  for(int i=0;i<b;i++){
    ll x,y,z;
    cin>>x>>y>>z;
    x--;
    y--;
    g[x].push_back({y,1-z});
    g[y].push_back({x,1-z});
  }
  for(int i=0;i<a;i++){
    if(tmp[i]==-1){
      ans*=2;
      ans%=mod;
      dfs(i,0);
    }
  }
  cout<<ans%mod<<endl;
}