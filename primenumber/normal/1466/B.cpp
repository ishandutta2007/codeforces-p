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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n;
    cin>>n;
    vi32 x(n);
    rep(i,n) cin>>x[i];
    sort(all(x));
    vector<bool> ok(2*n+2, false);
    rep(i,n) {
      if (ok[x[i]]) ok[x[i]+1] = true;
      else ok[x[i]] = true;
    }
    cout<<count(all(ok),true)<<"\n";
  }
  return 0;
}