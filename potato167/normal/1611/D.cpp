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
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	int root;
	vector<int> p(n),b(n),w(n,-1),q(n);
	rep(i,n){
		cin>>p[i],p[i]--;
		if(p[i]==i) root=i;
	}
	rep(i,n){
		cin>>b[i];
		b[i]--;
	}
	int tmp=0;
	int J=0;
	if(root!=b[0]){
		cout<<"-1\n";
		return ;
	}
	w[root]=0;
	rep(i,n){
		if(i==0) continue;
		int a=b[i];
		if(w[p[a]]==-1){
			J=1;
			break;
		}
		w[a]=tmp+1-q[p[a]];
		q[a]=tmp+1;
		tmp++;
	}
	if(J){
		cout<<"-1\n";
		return ;
	}else{
		rep(i,n){
			if(i) cout<<" ";
			cout<<w[i];
		}
		cout<<"\n";
	}
}