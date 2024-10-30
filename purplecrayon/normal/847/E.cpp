#include <bits/stdc++.h>
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
const int MAXN = 1e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10, MAXK=1e12+10;

vector<int> p, a;
bool v(int t){
    int dp=0;
    for (auto it : p) {
        for (int l=a[dp]; dp < sz(a); dp++){
            int r=a[dp]; int tot;
            if (r <= it){
                tot=it-l;
            } else if (l >= it) {
                tot=r-it;
            } else {
                tot=r-l+min(it-l, r-it);
            }
            if (tot > t) break;
        }
    }
    return dp==sz(a);
}
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++){
        if (s[i] == 'P') p.push_back(i);
        else if (s[i] == '*') a.push_back(i);
    }
    int lo=0, hi=1e9+10, mid=(lo+hi)/2;
    while (lo < mid && mid < hi){
        if (v(mid)) hi=mid;
        else lo=mid;
        mid=(lo+hi)/2;
    }
    cout << hi;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}