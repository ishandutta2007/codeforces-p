#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <set>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

ll nod1(ll a, ll b)
{
    return a ? nod1(b % a, a) : b;
}

ll nod(ll a, ll b)
{
    if (a > b)
        swap(a, b);
    return nod1(a, b);
}

ll nok(ll a, ll b)
{
    return a / nod(a, b) * b;
}

ll sum(vector<int> v)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
}

ll sum(vector<ll> v)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
}

bool letter(char c)
{
    return 'a' <= c && c <= 'z';
}

bool LETTER(char c)
{
    return 'A' <= c && c <= 'Z';
}

string intToStr1(ll n)
{
    return n ? intToStr1(n / 10) + (char)('0' + n % 10) : "";
}

string intToStr(ll n)
{
    return n ? intToStr(n) : "0";
}

ll strToInt(string s)
{
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans = 10 * ans + (s[i] - '0');
    return ans;
}

bool digit(char c)
{
    return '0' <= c && c <= '9';
}

bool prime(ll n)
{
    if (n == 1)
        return 0;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

const ld zero = 0;
const ll null = 0;
const ll INF = 1e18;
const ll MOD = 1000000007;
const ld PI = atan2(0, -1);
const int MAXN = 200001;
const int N = MAXN;
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<ll> a;

pair<int, int> dp[N];
unordered_map<ll, ll> qq;

ll st(ll t)
{
    if (qq[t] != 0)
        return qq[t] - 1;
    if (!t)
        return 1;
    ll x = st(t / 2);
    x *= x;
    if (t % 2)
        x *= 2LL;
    x %= MOD;
    qq[t] = x + 1;
    return x;
}

unordered_map<ll, ll> q;

ll f(ll y)
{
    if (q[y] != 0)
        return q[y] - 1;
    ll ans = st(y - 1) - 1;
    for (ll i = 2; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            ans = (ans - f(i)) % MOD;
            if (y != i * i)
                ans = (ans - f(y / i)) % MOD;
        }
    }
    ans = (ans % MOD + MOD) % MOD;
    q[y] = ans + 1;
    return ans;

}

int main()
{
   // freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
    fastRead;
    ll x, y;
    cin >> x >> y;
    if (y % x)
    {
        cout << 0;
        return 0;
    }
    y /= x;
    q[1] = 2;
   // int Q = 10000000;
    cout << f(y);
    return 0;
}