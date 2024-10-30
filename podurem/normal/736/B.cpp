#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <numeric>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "light"

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	solve();
}

const int dd = (int)1e5 + 7;
const int inf = (int)1e9 + 7;

inline bool ok(int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

int solve() {
	int n;
	scanf("%d", &n);
	if (ok(n)) return 0 * puts("1");

	if (n % 2 == 0 || ok(n - 2)) return 0 * puts("2");

	puts("3");

	return 0;
}