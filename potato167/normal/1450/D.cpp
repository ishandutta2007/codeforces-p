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
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

namespace po167{
template <class T,T (*op)(T,T),T(*e)()>
struct segment_tree{
	int _n,size;
	std::vector<T> seg;
	int ceil_pow2(int a){
		int b=1;
		while(a>b){
			b<<=1;
		}
		return b;
	}
	void update(int k){seg[k]=op(seg[k*2],seg[k*2+1]);};
	segment_tree(int n) :_n(n){
		size=ceil_pow2(n);
		seg=std::vector<T>(size*2,e());
	}
	segment_tree(std::vector<T> &p) :_n((int) p.size()){
		size=ceil_pow2(_n);
		seg=std::vector<T>(size*2,e());
		for(int i=0;i<_n;i++) seg[i+size]=p[i];
		for(int i=size-1;i>0;i--) update(i);
	}
	void set(int ind,T val){
		assert(0<=ind&&ind<_n);
		ind+=size;
		seg[ind]=val;
		while(ind!=1){
			ind>>=1;
			update(ind);
		}
	}
	T get(int ind){
		assert(0<=ind&&ind<_n);
		return seg[ind+size];
	}
	T query(int l,int r){
		assert(0<=l&&l<=r&&r<=_n);
		T l_val=e();
		T r_val=e();
		l+=size,r+=size;
		while(l<r){
			if(l&1) l_val=op(l_val,seg[l]),l+=1;
			if(r&1) r-=1,r_val=op(seg[r],r_val);
			r>>=1;
			l>>=1;
		}
		return op(l_val,r_val);
	}
	template <bool (*f)(T)> int max_right(int l) {
        return max_right(l, [](T x) { return f(x); });
    }
	template <class F> int max_right(int l, F f) {
		assert(0<=l&&l<=_n);
		assert(f(e()));
		if(f(query(l,_n))) return _n;
		T val=e();
		l+=size;
		while(true){
			while(l%2==0) l>>=1;
			if(!f(op(val,seg[l]))){
				while(l<size){
					l*=2;
					if(f(op(val,seg[l]))){
						val=op(val,seg[l]);
						l++;
					}
				}
				return l-size;
			}
			val=op(val,seg[l]);
			l++;
		}
	}
	template <bool (*f)(T)> int min_left(int r) {
        return min_left(r, [](T x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        T sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(seg[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(seg[r], sm))) {
                        sm = op(seg[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(seg[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

};
}
using po167::segment_tree;


using F= int;
F op(F a,F b){return min(a,b);}
F e(){return INF;}
int target;
bool f(F x){
	return (x%target==0);
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
	int n;
	cin>>n;
	vector<int> p(n);
	vector<int> q(n,-2);
	int l=0,R=n-1;
	rep(i,n){
		cin>>p[i];
		p[i]--;
		if(q[p[i]]==-2) q[p[i]]=i;
		else q[p[i]]=-1;
	}
	segment_tree<F,op,e> seg(n);
	rep(i,n) seg.set(i,p[i]);
	vector<int> ans(n,0);
	ans[n-1]=1;
	So(p);
	rep(i,n) if(p[i]!=i) ans[n-1]=0;
	rep(i,n){
		ans[i]=1;
		if(l==q[i]) l++;
		else if(R==q[i]) R--;
		else{
			vector<int> r;
			rep(j,i+1){
				r.push_back(seg.query(j,n-i+j));
			}
			So(r);
			ans[i]=1;
			rep(j,i+1){
				if(r[j]!=j) ans[i]=0;
			}
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		cout<<ans[i];
	}
	cout<<"\n";
}