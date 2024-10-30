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
  cout<< fixed << setprecision(10);
}

int main() {
  cincout();
  ll n,m;
  cin>>n>>m;
  ll d=0;
  while(d*d<=m) d++;
  d/=3;
  vector<ll> x(n),y(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
    chmin(x[i],m+10);
    chmin(y[i],m+10);
  }
  vector<vector<ll>> k(d+1);
  vector<ll> now(d+1);
  vector<ll> ans(m+10);
  vector<vector<ll>> t(n);
  vector<ll> type(m),u(m);
  for(int i=0;i<m;i++){
    cin>>type[i]>>u[i];
    u[i]--;
    t[u[i]].pb(i);
  }
  for(int i=0;i<n;i++) t[i].pb(m+5);
  for(int i=0;i<n;i++){
    if(x[i]+y[i]>d){
      ll s=x[i]+y[i];
      for(int j=0;j+1<t[i].size();j+=2){
        ll p=t[i][j];
        ll q=t[i][j+1];
        q--;
        ll v=0;
       // cout<<i<<" "<<p<<" "<<q<<endl;
        for(int d=p+s;d<=q;d+=s){
          ans[d]--;
          v++;
        } 
        for(int d=p+x[i];d<=q;d+=s){
          ans[d]++;
          v--;
        }
        if(v!=0) ans[q+1]--; 
      }
    }
    else{
      for(int j=0;j+1<t[i].size();j+=2){
        ll p=t[i][j];
        ll q=t[i][j+1];
        ll z=(q-p);
        if(z%(x[i]+y[i])==0||z%(x[i]+y[i])>x[i]) ans[q]--;
      }
    }
  }
  for(int i=1;i<=d;i++) k[i].resize(i);
  vector<ll> X(n),Y(n);
  for(int i=0;i<m;i++){
    if(x[u[i]]+y[u[i]]<=d&&type[i]==1){
      ll f=x[u[i]]+y[u[i]];
      k[f][(i+x[u[i]])%f]++;
      X[u[i]]=(i+x[u[i]])%f;
      Y[u[i]]=i%f;
     // cout<<f<<" "<<k[f][(i+x[u[i]])%f]<<" "<<k[f][i%f]<<" "<<(i+x[u[i]])%f<<" "<<i%f<<endl;
    }
    if(x[u[i]]+y[u[i]]<=d&&type[i]==2){
      ll f=x[u[i]]+y[u[i]];
      k[f][X[u[i]]]--;
      k[f][Y[u[i]]]++;
    }
    for(int j=1;j<=d;j++) ans[i]+=k[j][now[j]];
  //  for(int j=1;j<=d;j++) cout<<i<<" "<<j<<" "<<now[j]<<" "<<k[j][now[j]]<<endl;
    for(int j=1;j<=d;j++) (now[j]+=1)%=j;
    if(x[u[i]]+y[u[i]]>d) continue;
    if(x[u[i]]+y[u[i]]<=d&&type[i]==1){
      ll f=x[u[i]]+y[u[i]];
      k[f][i%f]--;
      X[u[i]]=(i+x[u[i]])%f;
      Y[u[i]]=i%f;
     // cout<<f<<" "<<k[f][(i+x[u[i]])%f]<<" "<<k[f][i%f]<<" "<<(i+x[u[i]])%f<<" "<<i%f<<endl;
    }
  }
  for(int i=1;i<m;i++) ans[i]+=ans[i-1];
  for(int i=0;i<m;i++) cout<<ans[i]<<endl;
}