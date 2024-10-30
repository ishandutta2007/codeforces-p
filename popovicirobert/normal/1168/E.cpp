#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

/*int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}*/

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, k, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> k;
    int sum = 0; n = 1 << k;
    vector <int> a(n), p(n), q(n), pos(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = q[i] = pos[i] = i;
        sum ^= a[i];
    }

    if(sum) { cout << "Fou\n"; return 0; }

    for(i = 0; i < n; i++) {
        int cur = i;
        while((p[cur] ^ q[cur]) != a[cur]) {
            int nxt = pos[a[cur] ^ q[cur]];
            swap(p[cur], p[nxt]), swap(pos[p[cur]], pos[p[nxt]]);
            if(nxt > i) { break; }
            swap(q[i + 1], q[nxt]);
            cur = nxt;
        }
    }

    cout << "Shi\n";
    for(auto it : p) {
        cout << it << " ";
    }
    cout << "\n";
    for(auto it : q) {
        cout << it << " ";
    }

    return 0;
}