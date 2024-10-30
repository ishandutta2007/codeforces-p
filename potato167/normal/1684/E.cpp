#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}


void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> p(n);
	rep(i,n) cin>>p[i];
	So(p);
	int MEX=0;
	int Z=0;
	int ind=0;
	while(true){
		if(ind==n||p[ind]!=MEX){
			MEX++;
			Z++;
			if(Z==k+1){
				Z--;
				break;
			}
			continue;
		}
		while(ind<n&&p[ind]==MEX){
			ind++;
		}
		MEX++;
	}
	vector<int> q;
	p.push_back(INF);
	int v=1;
	while(ind!=n){
		if(p[ind]==p[ind+1]) v++;
		else q.push_back(v),v=1;
		ind++;
	}
	So(q);
	int ans=q.size();
	rep(i,(int)(q.size())){
		Z-=q[i];
		if(Z>=0) ans--;
	}
	//vec_out(q);
	cout<<ans<<"\n";
}