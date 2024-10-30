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
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void out(int n){
	cout<<"? "<<n<<endl;
	return ;
}

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
	int n,tmp;
	cin>>n;
	vector<int> p(n+1,-1);
	p[0]=0;
	rep(i,n+1){
		if(p[i]!=-1) continue;
		out(i);
		cin>>tmp;
		vector<int> q={tmp};
		while(true){
			out(i);
			cin>>tmp;
			if(tmp==q[0]) break;
			q.push_back(tmp);
		}
		int ind=0;
		rep(j,(int)(q.size())){
			if(q[j]==i){
				ind=j;
				break;
			}
		}
		int m=q.size();
		rep(j,m){
			p[q[(ind+j)%m]]=q[(ind+j+1)%m];
		}
	}
	cout<<"!";
	rep(i,n) cout<<" "<<p[i+1];
	cout<<endl;
}