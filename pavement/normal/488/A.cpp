#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int A, B;

bool V(int X) {
	string S = to_string(X);
	for (char c : S)
		if (c == '8') return 1;
	return 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A;
	if (V(A)) A++, B++;
	while (!V(A)) A++, B++;
	cout << B << '\n';
}