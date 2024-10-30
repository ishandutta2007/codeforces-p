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
    vi32 candidates;
    rep(i,n) {
      if (a[i] != a[n-1-i]) {
        candidates.push_back(a[i]);
        candidates.push_back(a[n-1-i]);
        break;
      }
    }
    bool ok = candidates.empty();
    for (i32 del : candidates) {
      vi32 rem;
      for(auto&& e : a) {
        if (e == del) continue;
        rem.push_back(e);
      }
      auto r = rem;
      reverse(all(r));
      if (rem == r) ok = true;
    }
    if (ok) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }
  return 0;
}