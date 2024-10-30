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

void solve(){
    string s; cin >> s; int n = sz(s);
    vector<ll> dp(n+1, 0);
    for (int i = 0; i < n; i++) if (s[i] == 'm' || s[i] == 'w'){ cout << "0\n"; return; }
    dp[0] = 1; dp[1] = ((s[0]=='u'&&s[1]=='u')||(s[0]=='n'&&s[1]=='n'))?2:1;
    for (int i = 2; i < n; i++){
        if (((s[i-1]=='u'&&s[i]=='u')||(s[i]=='n'&&s[i-1]=='n'))) dp[i] = dp[i-2];
        dp[i] = (dp[i]+dp[i-1])%MOD;
    }
    cout << dp[n-1];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}