#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		int ans=0;
		int cur=a.back();
		for (int i=n-2; ~i; --i) {
			if (a[i]>cur) {
				cur=a[i];
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}