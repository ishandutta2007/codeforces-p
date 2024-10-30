// #include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pf push_front
#define pb2 pop_back
#define pf2 pop_front
#define line printf("\n")
#define pq priority_queue
#define rep(k,i,j) for(int k = (int)i;k<(int)j;k++)
#define repd(k,i,j) for(int k = (int)i;k>=(int)j;k--)
#define ll long long
#define ALL(a) a.begin(),a.end()
#define vi vector<int>

using namespace std;

double EPS = 1e-9;
int INF = 1e9+7;;
long long INFLL = 1e17;
double pi = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

//end of template

const int maxn = 2e5 + 5;
int n, m;


int main() {
	cin >> n >> m;
	
	int lst = 0;
	ll ans = 0;
	rep(k, 0, n) {
		int a;
		cin >> a;
		
		int make = (a + lst) / m ;
		
		if (make * m < lst) make ++;
		lst = (a + lst) - make * m;
		if (lst < 0) lst = 0;
		ans += make;
	}
	if (lst) ans++;
	
	cout << ans << endl;
}