#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif
 
using namespace std;
using namespace std::string_literals;
 
using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

//using namespace harudake;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n;
    cin>>n;
    vi32 a(n);
    rep(i,n) cin>>a[i];
    map<i32,i32> m;
    rep(i,n) {
      ++m[a[i]];
    }
    i32 ans = 0;
    for (auto&&[v,cnt] : m) {
      i32 num = cnt;
      auto itr = m.upper_bound(v);
      while (itr != end(m)) {
        i32 upper = itr->first;
        ++num;
        i32 nx = 2 * (upper - v) + v;
        itr = m.lower_bound(nx);
      }
      ans = max(ans, num);
    }
    cout<<(n-ans)<<"\n";
  }
  return 0;
}