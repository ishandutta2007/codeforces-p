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
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	string S,T;
	cin>>S>>T;
	rep(i,n){
		if(S[i]!=T[i]) S[i]='?';
	}
	int ans=0;
	int ind=0;
	while(ind<n){
		if(S[ind]=='?'){
			ans+=2;
			ind++;
			continue;
		}
		if(ind!=n-1&&S[ind+1]=='?'){
			ans+=(int)('1'-S[ind]);
			ans+=2;
			ind+=2;
			continue;
		}
		if(ind==n-1||S[ind]==S[ind+1]){
			ans+=(int)('1'-S[ind]);
			ind++;
			continue;
		}
		else{
			ans+=2;
			ind+=2;
		}
	}
	cout<<ans<<"\n";
}