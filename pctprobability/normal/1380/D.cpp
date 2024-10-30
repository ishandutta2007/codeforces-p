#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = long long;
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define all(s) (s).begin(),(s).end()
//#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
//#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define in scanner.read_int()
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 4500000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
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
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
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
class Scanner {
    vector<char> buffer;
    ssize_t n_written;
    ssize_t n_read;

public:
    Scanner(): buffer(1024*1024) { do_read(); }

    int64_t read_int() {
        int64_t ret = 0, sgn = 1;
        int ch = current_char();
        while (isspace(ch)) { ch = next_char(); }
        if (ch == '-') { sgn = -1; ch = next_char(); }
        for (; isdigit(ch); ch = next_char())
            ret = (ret * 10) + (ch - '0');
        return sgn * ret;
    }

private:
    void do_read() {
        ssize_t r = read(0, &buffer[0], buffer.size());
        if (r < 0) {
            throw runtime_error(strerror(errno));
        }
        n_written = r;
        n_read = 0;
    }

    inline int next_char() {
        ++n_read;
        if (n_read == n_written) { do_read(); }
        return current_char();
    }

    inline int current_char() {
        return (n_read == n_written) ? EOF : buffer[n_read];
    }
};

//Scanner scanner;
//void vin(vector<ll> &n){for(int i=0;i<int(n.size());i++) n[i]=in;}

void cincout(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(20);
}
ll subsolve(ll l,vector<ll> s,ll r,ll x,ll k,ll y){
  if(s.size()==0){
    return 0;
  }
 // cout<<"LR"<<" "<<l<<" "<<r<<endl;
 // for(auto e:s) cout<<e<<" ";
 // cout<<endl;
  ll p=0;
  ll f=s.size();
  for(auto e:s) chmax(p,e);
  if(f<k&&l<p&&r<p){
    return inf;
  }
  ll ans=inf;
  if(l>p||r>p){
    chmin(ans,f*y);
  }
  chmin(ans,(f%k)*y+((f-f%k)/k)*x);
  if(f>=k) chmin(ans,(f%k)*y+(f-f%k-k)*y+x);
  return ans;
}
void solve(){
  ll n,m;
  cin>>n>>m;
  ll x,k,y;
  cin>>x>>k>>y;
  vector<ll> a(n),b(m);
  vcin(a);
  vcin(b);
  map<ll,ll> p;
  map<ll,ll> q;
  ll count=1;
  for(auto e:a){
    p[e]=count;count++;
  }
  vector<ll> z;
  for(auto e:b){
    q[e]++;
    z.pb(p[e]);
    if(p[e]==0){
      cout<<-1<<endl;
      return;
    }
  }
  vector<ll> d=z;
  sor(d);
  if(d!=z){
    cout<<-1<<endl;
    return;
  }
  vector<ll> t;
  ll l=-1;
  a.pb(-1);
  ll ans=0;
  q[-1]=1;
  for(int i=0;i<n;i++){
    if(q[a[i]]==0){
      t.pb(a[i]);
    }
    else{
      ll tmp=subsolve(l,t,a[i],x,k,y);
     // cout<<"T"<<" "<<tmp<<endl;
      if(tmp==inf){
        cout<<-1<<endl;
        return;
      }
      ans+=tmp;
      l=a[i];
      t={};
    }
  }
  ll tmp=subsolve(l,t,-1,x,k,y);
  if(tmp==inf){
    cout<<-1<<endl;
    return;
  }
  ans+=tmp;
  cout<<ans<<endl;
}
int main() {
  cincout();
  ll t;
  t=1;
  while(t--){
    solve();
  }
}