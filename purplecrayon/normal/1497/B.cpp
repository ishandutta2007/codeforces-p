#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n); for (auto& it : a) cin >> it;

    vector<int> cnt(m);
    for (auto& it : a) cnt[it%m]++;

    int ans=0;
    for (int i = 1, j = m-1; i <= j; i++, j--){
        if (i != j){ 
            if (cnt[i] || cnt[j]){
                ans++;
                if (cnt[i] < cnt[j]) swap(cnt[i], cnt[j]);
                cnt[i] -= cnt[j]+1;
                ans += max(0, cnt[i]);
            }
        } else {
            if (cnt[i]) ans++;
        }
    }
    if (cnt[0]) ans++;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}