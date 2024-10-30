#include <bits/stdc++.h>
using namespace std;

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

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MAXP = 2e5+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<pair<ll, ll>> a(n); 
    for (auto& it : a) cin >> it.first;
    for (auto& it : a) cin >> it.second;
    map<ll, vector<ll>> mp;
    sort(a.begin(), a.end());
    multiset<ll> ms; ll c=a[0].first, s=0;
    for (auto it : a) {
        mp[it.first].push_back(it.second);
        if (it.first == c) ms.insert(it.second), s += it.second;
    }
    ll ans=0;
    while (sz(ms)){
        auto it = prev(ms.end());
        s -= *it; ms.erase(it);
        ans += s; c++;
        if (mp.count(c)) for (auto it : mp[c]) ms.insert(it), s += it;
        if (!sz(ms) && mp.upper_bound(c) != mp.end()){
            c = mp.upper_bound(c)->first;
            for (auto it : mp[c]) ms.insert(it), s += it;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}