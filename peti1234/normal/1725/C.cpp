#include <bits/stdc++.h>

using namespace std;


/*
c meg mod erteket be kell allitani
calc n utan n-ig tud faktorialis, inverz es a alatt b-t szamolni
*/


const int c=600005;
long long mod=998244353;



long long fakt[c], inv[c];
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}

long long alatt(long long a, long long b) {
    if (a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}

void calc(int a) {
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=a; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
}

long long n, m, sum, spec, ans;
set<long long> s;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        long long x;
        cin >> x;
        sum+=x;
        s.insert(sum);
    }
    for (auto x:s) {
        if (sum%2==0 && s.count(x+sum/2)) {
            spec++;
        }
    }
    calc(n+m);
    for (int i=0; i<=min(m, spec); i++) {
        if (i==m && 2*i<n || i==m-1 && i<spec) continue;
        ans=(ans+alatt(spec, i)*alatt(m, i)%mod*fakt[i]%mod*po(m-i, n-spec-i)%mod*po(m-i-1, spec-i)%mod)%mod;
    }
    cout << ans << "\n";
    return 0;
}