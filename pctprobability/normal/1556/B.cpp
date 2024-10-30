#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>
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
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define all(s) (s).begin(),(s).end()
//#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
//#define rep(i, n) rep2(i, 0, n)
#define PB push_back 
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
//#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define NP next_permutation
//const ll mod = 1000000009;
const ll mod = 998244353;
//const ll mod = 1000000007;
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
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll fastgcd(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}
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
  cout<< fixed << setprecision(10);
}
struct SegTree{
  vector<ll> node;
  ll n;
  SegTree(){
  }
  SegTree(vector<ll> a){
    ll N=a.size();
    n=1;
    while(n<N) n*=2;
    node.resize(2*n-1);
    for(int i=0;i<2*n-1;i++) node[i]=0;
    for(int i=n-1;i<n-1+a.size();i++) node[i]=a[i-(n-1)];
  }
  void build(){
    for(int i=n-2;i>=0;i--) node[i]=node[i*2+1]+node[i*2+2];
  }
  void update(ll a,ll b){
    a+=n-1;
    node[a]+=b;
    while(a){
      a=(a-1)/2;
      node[a]+=b;
    }
  }
  ll sub_query(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b) return node[k];
    else{
      return sub_query(a,b,2*k+1,l,(l+r)/2)+sub_query(a,b,2*k+2,(l+r)/2,r);
    }
  }
  ll query(ll a,ll b){
    return sub_query(a,b,0,0,n);
  }
};
ll inversions(vector<ll> a){
  auto n=a;
  ll nmax=0;
  for(int i=0;i<int(n.size());i++){
    chmax(nmax,n[i]);
  }
  nmax++;
  ll ans=0;
  vector<ll> k(nmax);
  SegTree seg(k);
  for(int i=0;i<int(n.size());i++){
    seg.update(n[i],seg.query(n[i],n[i]+1)+1);
    if(n[i]+1!=nmax){
      ans+=seg.query(n[i]+1,nmax);
    }
  }
  return ans;
}
void solve(){
  ll a;
  cin>>a;
  vector<ll> n(a);
  vcin(n);
  ll x=0;
  for(int i=0;i<a;i++){
    n[i]%=2;
    x+=n[i];
  }
  if(a%2){
    if(x==a/2){
      ll ans=inf;
      vector<ll> k(a);
      ll p=0,q=0;
      for(int i=0;i<a;i++){
        if(n[i]){
          k[2*p+1]=i;
          p++;
        }
        else{
          k[2*q]=i;
          q++;
        }
      }
      chmin(ans,inversions(k));
      cout<<ans<<endl;
    }
    else if(x==(a+1)/2){
      ll ans=inf;
      vector<ll> k(a);
      ll p=0,q=0;
      for(int i=0;i<a;i++){
        if(!n[i]){
          k[2*p+1]=i;
          p++;
        }
        else{
          k[2*q]=i;
          q++;
        }
      }
      chmin(ans,inversions(k));
      cout<<ans<<endl;
    }
    else{
      cout<<-1<<endl;
      return;
    }
  }
  else{
    if(x==a/2){
      ll ans=inf;
      vector<ll> k(a);
      ll p=0,q=0;
      for(int i=0;i<a;i++){
        if(n[i]){
          k[2*p+1]=i;
          p++;
        }
        else{
          k[2*q]=i;
          q++;
        }
      }
      chmin(ans,inversions(k));
      p=0,q=0;
      for(int i=0;i<a;i++){
        if(!n[i]){
          k[2*p+1]=i;
          p++;
        }
        else{
          k[2*q]=i;
          q++;
        }
      }
      chmin(ans,inversions(k));
      cout<<ans<<endl;
    }
    else{
      cout<<-1<<endl;
      return;
    }
  }
}
int main() {
  cincout();
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}