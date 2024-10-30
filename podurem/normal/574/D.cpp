#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define for1(i, n) for (int i = 1; i <= (int)n; i++)
#define forq(i, s, t) for (int i = s; i <= (int)t; i++)
#define ford(i, s, t) for (int i = s; i >= (int)t; i--)
#define mk make_pair
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK ""

const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const ll P = 239017;

int solve();

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//freopen("test.txt", "w", stderr);
	double tstart = TIME;
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
#ifdef _DEBUG
	double tend = TIME;
	cerr << tend - tstart << " s.\n";
#endif
	return 0;
}

vi ans, a;

int solve()
{
	int n;
	cin >> n;
	ans.resize(n);
	a.resize(n);
	forn(i, n)
	{
		cin >> a[i];
		ans[i] = a[i];
	}
	ans[0] = 1;
	ans[n - 1] = 1;
	bool f = 1;
	while (f)
	{
		f = 0;
		forq(i, 1, n - 2)
		{
			if (ans[i] > ans[i - 1] + 1)
			{
				f = 1;
				ans[i] = ans[i - 1] + 1;
			}
			if (ans[i] > ans[i + 1] + 1)
			{
				f = 1;
				ans[i] = ans[i + 1] + 1;
			}
		}
		ford(i, n - 2, 1)
		{
			if (ans[i] > ans[i - 1] + 1)
			{
				f = 1;
				ans[i] = ans[i - 1] + 1;
			}
			if (ans[i] > ans[i + 1] + 1)
			{
				f = 1;
				ans[i] = ans[i + 1] + 1;
			}
		}
	}
	cout << ans[max_element(ans.begin(), ans.end()) - ans.begin()];
	return 0;
}