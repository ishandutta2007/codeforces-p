#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define ass(n,l,r) assert(n>=l and n<=r)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}

int main()
{
  boost;
 	int n,h,k;cin>>n>>h>>k;
 	vi a(n);
 	
 	FOR(i,1,n)cin>>a[i-1];
 	int now=0;
 	ll ans=0;
 	FOR(i,0,n-1){
 		if(now+a[i]>h){
 			if(now<k)
 				ans++,now=0;
 			else
 				ans+=now/k,now%=k;
 			--i;
 			continue;
 		}
 		now+=a[i];
 	}
 	while(now){
 		if(now<k)
 				ans++,now=0;
 			
 			else
 				ans+=(now)/k,now%=k;
 		}
 	cout<<ans; 
  return 0;
}