#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<pair<ll, ll>> q(n);
    for (int i = 0; i < n; i++)
        cin >> q[i].first;
    for (int i = 0; i < n; i++)
        cin >> q[i].second;
    sort(q.begin(), q.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        ll cur = q[i].first;
        while (true)
        {
            if (j >= n || q[j].first > cur)
                break;
            cur++;
            j++;
        }
        set<pair<pair<ll, ll>, int> > s;
        cur = q[i].first;
        int it = i;
        for (int k = i; k < j; k++)
        {
            while (it < j && q[it].first <= cur)
                s.insert({{-q[it].second, q[it].first}, it}), it++;
            assert(sz(s));
            auto d = s.begin()->first;
            ans += (cur - d.second) * (-d.first);
            s.erase(s.begin());
            cur++;
        }
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
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