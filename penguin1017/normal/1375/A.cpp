#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
int a[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		rep(i,0,n)scanf("%d",&a[i]);
		rep(i,0,n){
			if(i&1)a[i]=abs(a[i]);
			else a[i]=-abs(a[i]);
		}
		rep(i,0,n)printf("%d ",a[i]);
		printf("\n");
	}
}