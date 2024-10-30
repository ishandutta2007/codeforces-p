#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

void cyc(vector<int> &p,int l,int r,int d){
	rep(i,d){
		for(int j=l;j<r;j++){
			swap(p[j+1],p[j]);
		}
	}
}

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t){
		int n;
		cin>>n;
		vector<int> p(n);
		rep(i,n) cin>>p[i];
		int minimum=INF;
		vector<int> q,r;
		rep(i,n){
			if(chmin(minimum,p[i])) q.push_back(p[i]);
			else r.push_back(p[i]);
		}
		reverse(q.begin(),q.end());
		for(auto x:r) q.push_back(x);
		rep(i,n){
			if(i!=0) cout<<" ";
			cout<<q[i];
		}
		cout<<"\n";
	}
}