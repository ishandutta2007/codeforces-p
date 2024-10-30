#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
/*#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif*/
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
ll poplong(ll x){ll y=0;while(x){x/=2;y++;}return y;}

void cincout() {
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
}
struct graph{
  struct edge{
    ll to,cost;
  };
  ll v;
  vector<vector<edge>> g;
  vector<ll> d;
  vector<bool> negative;
  vector<bool> diameter;
  vector<ll> topological_sort;
  ll diametercost;
  bool bipartitecheck;
  vector<ll> bipartite;
  graph(ll n){
    init(n);
  }
  void init(ll n){
    v=n;
    g.resize(n);
    d.resize(n);
    negative.resize(n);
    diameter.resize(n);
    bipartite.resize(n);
    for(int i=0;i<v;i++){
      d[i]=inf;
      bipartite[i]=-1;
      negative[i]=false;
      diameter[i]=false;
    }
  }
  void addedge(ll s,ll t,ll cost){
    edge e;
    e.to=t;
    e.cost=cost;
    g[s].push_back(e);
  }
  void dijkstra(ll s){
    for(int i=0;i<v;i++){
      d[i]=inf;
    }
    d[s]=0;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,s));
    while(!que.empty()){
      P p=que.top();
      que.pop();
      ll V=p.second;
      if(d[V]<p.first) continue;
      for(auto e:g[V]){
        if(d[e.to]>d[V]+e.cost){
          d[e.to]=d[V]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
  void BellmanFord(ll s){
    for(int i=0;i<v;i++){
      d[i]=inf;
      negative[i]=false;
    }
    d[s]=0;
    for(int i=0;i<v;i++){
      for(int V=0;V<v;V++){
        if(d[V]==inf){
          continue;
        }
        for(auto e:g[V]){
          if(d[e.to]>d[V]+e.cost){
            d[e.to]=d[V]+e.cost;
            if(i==v-1){
              negative[e.to]=true;
              negative[V]=true;
            }
          }
        }
      }
    }
  }
  void bfs(ll s){
    for(int i=0;i<v;i++){
      d[i]=inf;
    }
    d[s]=0;
    queue<ll> q;
    q.push(s);
    while(q.size()){
      ll v=q.front();
      q.pop();
      for(auto e:g[v]){
        assert(e.cost==1);
        if(chmin(d[e.to],d[v]+1)) q.push(e.to);
      }
    }
  }
  void treediameter(){
    bfs(0);
    ll p=0;
    ll q=0;
    for(int i=0;i<v;i++){
      if(q<d[i]){
        q=d[i];
        p=i;
      }
    }
    diameter[p]=true;
    bfs(p);
    ll p2=0;
    ll q2=0;
    for(int i=0;i<v;i++){
      if(q2<d[i]){
        q2=d[i];
        p2=i;
      }
    }
    diameter[p2]=true;
    diametercost=d[p2];
  }
  void Bipartite(){
    for(int i=0;i<v;i++){
      if(bipartite[i]==-1){
        Bipartitedfs(i);
      }
    }
  }
  void Bipartitedfs(ll s,ll cur=0){
    bipartite[s]=cur;
    for(auto e:g[s]){
      if(bipartite[e.to]!=-1){
        if((bipartite[e.to]==bipartite[s])^(!e.cost%2)){
          bipartitecheck=false;
        }
      }
      else{
        if(e.cost%2){
          Bipartitedfs(e.to,1-cur);
        }
        else{
          Bipartitedfs(e.to,cur);
        }
      }
    }
  }
  void topologicalsort(){
    for(int i=0;i<v;i++){
      d[i]=0;
    }
    for(int i=0;i<v;i++){
      if(d[i]) continue;
      topologicaldfs(i);
    }
    rever(topological_sort);
  }
  void topologicaldfs(ll a){
    d[a]=1;
    for(auto e:g[a]){
      if(d[e.to]) continue;
      topologicaldfs(e.to);
    }
    topological_sort.push_back(a);
  }
};
class UnionFind{
public:
  vector<ll> par;
  vector<ll> siz;
  UnionFind(ll sz_):par(sz_),siz(sz_,1ll){
    for(int i=0;i<sz_;i++) par[i]=i;
  }
  void init(ll sz_){
    par.resize(sz_);
    siz.assign(sz_,1ll);
    for(int i=0;i<sz_;i++) par[i]=i;
  }
  ll root(ll x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool merge(ll x,ll y){
    x=root(x);
    y=root(y);
    if(x==y) return false;
    if(siz[x]<siz[y]) swap(x,y);
    siz[x]+=siz[y];
    par[y]=x;
    return true;
  }
  bool issame(ll x,ll y){
    return root(x)==root(y);
  }
  ll size(ll x){
    return siz[root(x)];
  }
};
namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
int main(){
  cincout();
  int n,m,q;
  cin>>n>>m>>q;
  vector<array<int,4>> h(m);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    array<int,4> x;
    x[0]=c;
    x[1]=a;
    x[2]=b;
    x[3]=i;
    h[i]=x;
  }
  sor(h);
  rever(h);
  vector<int> l(q),r(q);
  for(int i=0;i<q;i++){
    cin>>l[i]>>r[i];
    l[i]--;
    r[i]--;
  }
  for(int i=0;i<q;i++){
    dsu t(2*n);
    int ans=-1;
    for(int j=0;j<m;j++){
      if(l[i]<=h[j][3]&&h[j][3]<=r[i]){
        t.merge(h[j][1]+n,h[j][2]);
        t.merge(h[j][1],h[j][2]+n);
        if(t.same(h[j][1],h[j][1]+n)){
          ans=h[j][0];
          break;
        }
      }
    }
    cout<<ans<<endl;
  }
}