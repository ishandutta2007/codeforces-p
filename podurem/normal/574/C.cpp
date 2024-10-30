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
typedef pair<long double, long double> pll;
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

int solve()
{
	int n, ind, max1 = 0;
	cin >> n;
	vector <int> a(n);
	forn(i, n)
	{
		cin >> a[i];
		if (max1 < a[i])
		{
			max1 = a[i];
			ind = i;
		}
	}
	while (max1 % 2 == 0)
		max1 /= 2;
	while (max1 % 3 == 0)
		max1 /= 3;
	forn(i, n)
		if (ind != i)
		{
			if (a[i] % max1 == 0)
			{
				a[i] /= max1;
				while (a[i] % 2 == 0)
					a[i] /= 2;
				while (a[i] % 3 == 0)
					a[i] /= 3;
				if (a[i] != 1)
				{
					cout << "No";
					return 0;
				}
			}
			else
			{
				cout << "No";
				return 0;
			}
		}
	cout << "Yes";
	return 0;
}