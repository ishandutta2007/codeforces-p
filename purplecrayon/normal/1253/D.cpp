#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int c, int &mn, int &mx){
    mn = min(mn, c); mx = max(mx, c); vis[c]=1;
    for (auto nxt : adj[c]) if (!vis[nxt]) dfs(nxt, mn, mx);
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    vector<pair<int, int>> v; memset(vis, 0, sizeof(vis));
    int tot=0;
    for (int i = 0; i < n; i++) if (!vis[i]){
        int mn=i, mx=i; tot++;
        dfs(i, mn, mx);
        v.push_back({mn, mx}); //cout << i << ' ' << mn << ' ' << mx << '\n';
    }
    sort(v.begin(), v.end());
    int ans=0, en=-1;
    for (auto it : v){
        if (en < it.first) ans++;
        en = max(en, it.second);
    }
    cout << (tot-ans) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}