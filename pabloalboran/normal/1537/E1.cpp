#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
   cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io() {
   cin.tie(0)->sync_with_stdio(0);
}
void file_io(string taskname) {
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

int main(){
    fast_io();

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<char> best(k, 'z');
    for(int i=1; i<=n; i++){
    	vector<char> curr(k);
    	bool better = false, worse = false;

    	forn(j, k){
    		curr[j] = s.at(j%i);
    		if(curr[j] < best[j] && !worse){
    			better = true;
    		}else if(curr[j] > best[j] && !better){
            worse = true;
         }
    	}
    	if(better){
    		best = curr;
    	}
    }
    forn(i, k){
    	cout << best[i];
    }
    cout << "\n";
}