#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
typedef long long ll;
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

vector<int> v(100007);

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
		
	for (int i = 0; i < n; i++)
		if (v[i] >= 0)
			v[i] = -v[i]-1;
	
	int minpos = 0;
	if (n % 2 == 1) {
		for (int i = 1; i < n; i++)
			if (v[i] < v[minpos])
				minpos = i;
				
		v[minpos] = -v[minpos]-1;
	}
	
	for (int i = 0; i < n; i++)
		cout << v[i] SP;
		
	return 0;
}
 
/*
  _____                                               _               _       _                   _ _ 
 |  __ \                                             (_)             (_)     | |                 | | |
 | |__) | __ ___   __ _ _ __ __ _ _ __ ___  _ __ ___  _ _ __   __ _   _ ___  | |__   __ _ _ __ __| | |
 |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \| '_ ` _ \| | '_ \ / _` | | / __| | '_ \ / _` | '__/ _` | |
 | |   | | | (_) | (_| | | | (_| | | | | | | | | | | | | | | | (_| | | \__ \ | | | | (_| | | | (_| |_|
 |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|_| |_| |_|_|_| |_|\__, | |_|___/ |_| |_|\__,_|_|  \__,_(_)
                   __/ |                                       __/ |                                  
                  |___/                                       |___/                                                                                 
*/

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
template <class T1, class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << '(' << p.first << ',' << p.second << ')';
}
template <template <class...> class _TContainer, class... _T>
ostream& operator << (ostream& out, _TContainer<_T...>& _Container) {	
    out << '[';
    bool first = 1;
    for(auto x : _Container) {
    	if (!first) out << ',';
    	out << x;
    	first = 0;
    }
    out << ']';
    return out;
}