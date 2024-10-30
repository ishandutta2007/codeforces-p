#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN], lv=0;
vector<int> ch[MAXN];

int dfs(int c=0){
    int dp=(a[c]?1e9:0);
    for (auto nxt : ch[c]){
        if (a[c]) dp = min(dp, dfs(nxt));
        else dp += dfs(nxt);
    }
    if (!sz(ch[c])) dp=1;
    // cout << c << ' ' << dp << '\n';
    return dp;
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        int p; cin >> p, --p;
        ch[p].push_back(i);
    }
    for (int i = 0; i < n; i++) if (!sz(ch[i])) lv++;
    cout << (lv-dfs(0)+1) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}