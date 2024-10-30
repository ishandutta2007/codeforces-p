#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define _GLIBCXX_DEBUG
#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()
#define For(i, n) for (int i = 0; i < n; i++)
#define fi first
#define se second

int nod(int a, int b)
{
    return a ? nod(b % a, a) : b;
}

int nok(int a, int b)
{
    return a / nod(a, b) * b;
}

string intToStr(ll n)
{
    return n ? intToStr(n / 10) + (char)('0' + n % 10) : "";
}

long long sum(vector<int> v)
{
    int ans = 0;
    For(i, v.size())
        ans += v[i];
    return ans;
}

bool prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool letter(char c)
{
    return 'a' <= c && c <= 'z';
}

bool LETTER(char c)
{
    return 'A' <= c && c <= 'Z';
}

bool digit(char c)
{
    return ('0' <= c && c <= '9');
}

const ld PI = 3.141592653589793238462643383279;
const ld eps = 1e-8;
const ld zero = 0;
const ll null = 0;
const ll INF = 1e18;
//const int INF = 1e9;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAXN = 200001;
const int MAXM = 1001;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 1;
        return 0;
    }
    if (n % 4 == 1)
        cout << 8;
    if (n % 4 == 2)
        cout << 4;
    if (n % 4 == 3)
        cout << 2;
    if (n % 4 == 0)
        cout << 6;
    return 0;
}