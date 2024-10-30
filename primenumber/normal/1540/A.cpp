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
  i64 t;
  cin>>t;
  while(t--) {
    i64 n;
    cin>>n;
    vi64 d(n);
    rep(i,n) cin>>d[i];
    i64 mx = *max_element(all(d));
    sort(all(d));
    i64 ans = mx;
    rep(i,n-1) {
      i64 len = d[i+1] - d[i];
      ans -= len * (i+1) * (n-i-1);
    }
    cout<<ans<<endl;
  }
  return 0;
}