#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
//#define string basic_string<unsigned char>
#define char unsigned char

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    vector<ll> a(n);
    ll sum = 0;
    for (ll &i : a)
        cin >> i, sum += i;
    if (n < 3 || m < n)
    {
        cout << "-1\n";
        return 0;
    }
    cout << sum * 2 << '\n';
    for (int i = 0; i < n; i++)
        cout << i + 1 << ' ' << (i + 1) % n + 1 << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}