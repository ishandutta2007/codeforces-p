#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
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
#define P pair<ll,ll>
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
void solve(){
  ll a,b;
  cin>>a>>b;
  vector<ll> n(a);
  vcin(n);
  ll o=0,z=0;
  for(int i=0;i<a;i++){
    if(n[i]==0){
      z++;
    }
    else{
      o++;
    }
  }
  for(int i=0;i<b;i++){
    ll x;
    cin>>x;
    if(x==1){
      ll c;
      cin>>c;
      c--;
      if(n[c]==0){
        n[c]=1;
        o++;
        z--;
      }
      else{
        n[c]=0;
        o--;
        z++;
      }
    }
    else{
      ll s;
      cin>>s;
      if(s<=o){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
  }
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll t;
 // cin>>t;
  t=1;
  while(t--){
    solve();
  }
}