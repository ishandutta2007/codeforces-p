#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

vector<int> adj[MAXN];
int cnt[2];

void dfs(int c=0, int p=-1, int col=0){
    cnt[col]++;
    for (auto nxt : adj[c]) if (nxt != p) {
        dfs(nxt, c, col^1);
    }
}

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs();
    cout << max(min(cnt[0], cnt[1])-1, 0);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}