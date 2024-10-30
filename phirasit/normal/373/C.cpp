/*
#include <iostream>
#define LL long long

using namespace std;

LL w,m,k;

int main() {
	cin >> w >> m >> k;
	w /= k;
	LL ans = 0,o = 1,l = 1;
	while(m <= k) {
		while(l*10 <= m) {
			o++;
			l *= 10;
		}
		cout << m << ' ';
		ans += o;
		m++;
	}
	cout << ans << '\n';
	return 0;
}*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[500010];
int use[500010];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		use[i] = 0;
	}
	sort(arr,arr+n);
	int a = 0,b = n/2;
	while(a < b) {
		int m = (a+b)/2 + 1;
		for(i=0;i<m;i++) {
			if(2*arr[i] > arr[n-m+i])
				break;
		}
		if(i < m)
			b = m-1;
		else
			a = m;
	}
	printf("%d\n",n-b);
	return 0;
}