#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define endl "\n"
typedef pair<int, int> Pii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(s) (s).begin(),(s).end()
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define PQminll priority_queue<ll, vector<ll>, greater<ll>>
#define PQmaxll priority_queue<ll,vector<ll>,less<ll>>
#define PQminP priority_queue<P, vector<P>, greater<P>>
#define PQmaxP priority_queue<P,vector<P>,less<P>>
#define NP next_permutation
//const ll mod = 1000000009;
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.00000000001);
//static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T,class K>void vcin(vector<T> &n,vector<K> &m){for(int i=0;i<int(n.size());i++) cin>>n[i]>>m[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
template<class T>void vcin(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cin>>n[i][j];}}}
template<class T>void vcout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<" ";}cout<<endl;}cout<<endl;}
void yes(bool a){cout<<(a?"yes":"no")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void possible(bool a){ cout<<(a?"possible":"impossible")<<endl; }
void Possible(bool a){ cout<<(a?"Possible":"Impossible")<<endl; }
void POSSIBLE(bool a){ cout<<(a?"POSSIBLE":"IMPOSSIBLE")<<endl; }
template<class T>auto min(const T& a){ return *min_element(all(a)); }
template<class T>auto max(const T& a){ return *max_element(all(a)); }
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
ll fastgcd(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}
P hyou(P a){ll x=fastgcd(abs(a.fi),abs(a.se));a.fi/=x;a.se/=x;if(a.se<0){a.fi*=-1;a.se*=-1;}return a;}
P Pplus(P a,P b){ return hyou({a.fi*b.se+b.fi*a.se,a.se*b.se});}
P Ptimes(P a,ll b){ return hyou({a.fi*b,a.se});}
P Ptimes(P a,P b){ return hyou({a.fi*b.fi,a.se*b.se});}
P Pminus(P a,P b){ return hyou({a.fi*b.se-b.fi*a.se,a.se*b.se});}
P Pgyaku(P a){ return hyou({a.se,a.fi});}
template<class T>
struct Sum{
  vector<T> data;
  Sum(const vector<T>& v):data(v.size()+1){
    for(ll i=0;i<v.size();i++) data[i+1]=data[i]+v[i];
  }
  T get(ll l,ll r) const {
    return data[r]-data[l];
  }
};
template<class T>
struct Sum2{
  vector<vector<T>> data;
  Sum2(const vector<vector<T>> &v):data(v.size()+1,vector<T>(v[0].size()+1)){
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]=data[i][j+1]+v[i][j];
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]+=data[i+1][j];
  }
  T get(ll x1,ll y1,ll x2,ll y2) const {
    return data[x2][y2]+data[x1][y1]-data[x1][y2]-data[x2][y1];
  }
};

void cincout(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(15);
}
constexpr ll MAX = 300000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
ll binom(ll n,ll k){
  if(n<k) return 0;
  if(n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
ll HOM(ll n,ll k){
  if(n+k-1>=n-1&&n-1>=0){
  return binom(n+k-1,n-1);
  }
  else{
    return 0;
  }
}
int main() {
  cincout();
  COMinit();
  ll n,k;
  cin>>n>>k;
  vector<ll> b(n);
  vcin(b);
  vector<ll> f(n+1);
  f[0]=0;
  f[1]=mod-1;
  for(ll i=1;i<n;i++){
    //(i/N)(1-1/K)(f(i-1)-f(i))+(1-i/N)(1/K)(f(i+1)-f(i))= -1/K
    ll u=i*modPow(n,mod-2,mod);
    u%=mod;
    u*=(1ll+mod-modPow(k,mod-2,mod));
    u%=mod;
    u+=mod;
    u%=mod;
    u*=(f[i-1]-f[i]);
    u%=mod;
    u+=mod;
    u%=mod;
    u=-u-modPow(k,mod-2,mod);
    u%=mod;
    u+=mod;
    u%=mod;
    u*=modPow((1+mod-i*modPow(n,mod-2,mod))+mod%mod+mod%mod,mod-2,mod);
    u%=mod;
    u*=k;
    u%=mod;
    u+=f[i];
    u%=mod;
    f[i+1]=u;
  }
  ll zero=0;
  map<ll,ll> m;
  for(auto e:b){
    if(e==-1) zero++;
    else m[e]++;
  }
  ll ans=0;
  vector<ll> g(n+1);
  ll u=0;
  for(auto e:m){
    u++;
    g[e.se]++;
  }
  g[0]=k-u;
  vector<ll> kai(n+1);
  vector<ll> Kpow(n+10);
  Kpow[0]=1;
  for(int i=1;i<=n+5;i++) Kpow[i]=(Kpow[i-1]*(k-1))%mod;
  for(int i=0;i<=n;i++){
    if(g[i]==0) continue;
    for(int j=i;j<=n;j++){
      if(zero<j-i) continue;
      //-1 i  j  -> g[i] * binom(zero,j-i) * (k-1)^(zero-(j-i))
      (kai[j]+=g[i]*binom(zero,j-i)%mod*Kpow[zero-(j-i)]%mod);
      while(kai[j]>=mod) kai[j]-=mod;
    }
  }
  for(int i=0;i<=n;i++){
   // cout<<f[i]<<" "<<kai[i]<<endl;
    ans+=f[i]*kai[i];
    ans%=mod;
  }
  ans*=modPow(modPow(k,zero,mod),mod-2,mod);
  ans-=f[n];
  ans%=mod;
  ans+=mod;
  ans%=mod;
  cout<<ans<<endl;
}