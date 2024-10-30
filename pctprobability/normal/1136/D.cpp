#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
const ll mod = 998244353;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll a,b;
  cin>>a>>b;
  vector<ll> n(a);
  vcin(n);
  map<pair<ll,ll>,ll> ma;
  for(int i=0;i<b;i++){
    ll x,y;
    cin>>x>>y;
    pair<ll,ll> z;
    z.fi=x;
    z.se=y;
    ma[z]++;
  }
  ll ans=0;
  vector<ll> d;
  d.push_back(n[a-1]);
  for(int i=a-2;i>=0;i--){
    bool t=true;
    for(int j=0;j<int(d.size());j++){
      ll x,y;
      x=n[i];
      y=d[j];
      pair<ll,ll> z;
      z.fi=x;
      z.se=y;
      if(ma[z]==0){
        t=false;
        break;
      }
    }
    if(t){
      ans++;
    }
    else{
      d.push_back(n[i]);
    }
  }
  cout<<ans<<endl;
}