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
typedef pair<int,int> Pii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define PB push_back
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
//typedef string::const_iterator State;
//class ParseError {};
//const ll mod = 1000000009;
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
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
template<class T>void print(T a){cout<<a<<endl;}
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

void cincout() {
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
}

struct sparsetable{
  vector<vector<ll>> node;
  sparsetable(vector<ll> a){
    ll n=a.size();
    ll k=0,x=n;
    while(x){
      k++;
      x/=2;
    }
    node.resize(k);
    for(int i=0;i<k;i++) node[i].resize(n);
    for(int i=0;i<n;i++) node[0][i]=a[i];
    for(int i=1;i<k;i++){
      for(int j=0;j<n;j++){
        node[i][j]=gcd(node[i-1][j],node[i-1][min(j+(1<<(i-1)),int(n-1))]);
      }
    }
  }
  ll query(ll a,ll b){
    if(a==b-1) return node[0][a];
    ll k=31-__builtin_clz(b-a);
    return gcd(node[k][a],node[k][b-(1<<k)]);
  }
};
void solve(){
  ll n;
  cin>>n;
  ll last=-1;
  vector<ll> a(n);
  vcin(a);
  sparsetable st(a);
  ll ans=0;
  map<int,int> m;
  for(int i=0;i<n;i++){
    m[a[i]]++;
    map<int,int> m2;
    for(auto e:m) m2[gcd(e.fi,a[i])]+=e.se;
    int now=0;
    m=m2;
    vector<P> v;
    for(auto e:m) v.pb(e);
    rever(v);
    bool f=false;
    for(auto e:v){
      //i=4 gcd 3 -> i-gcd+1
      ll ind=i-e.fi+1;
      if(last<ind&&st.query(ind,i+1)==e.fi){
        f=true;
        break;
      }
    }
    if(f){
      last=i;
      ans++;
      m.clear();
    }
    cout<<ans<<" ";
  }
  cout<<endl;
}
int main(){
  cincout();
  ll t;
 // cin>>t;
  t=1;
  while(t--){
    solve();
  }
}