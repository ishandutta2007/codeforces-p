#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1.5e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;
    
    auto v = [&](ll x){
        ll sm=0;
        for (int i = 0; i < n; i++) if (a[i] > x) sm += b[i];
        return sm <= x;
    };
    
    ll lo=-1, hi=1e18, mid=(lo+hi)/2;
    while (lo < mid && mid < hi){
        if (v(mid)) hi=mid;
        else lo=mid;
        mid=(lo+hi)/2;
    }
    cout << hi << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}