#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common DS shorteners
using ll = long long; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using um = unordered_map<K, V>; template <typename K, typename V> using om = map<K, V>;
template <typename K> using us = unordered_set<K>; template <typename K> using os = set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define pb push_back
// Shorthand Function Macros
#define FORI(a, b) for (int i = a; i < b; i++)
#define FORJ(a, b) for (int j = a, j < b; j++)
#define FORK(a, b) for (int k = a; k < b; k++)
#define CMPLT(type) bool operator<(const type &a, const type &b)
#define CMPGT(type) bool operator>(const type &a, const type &b)
#define CMPFN(type) bool operator()(const type &a, const type &b)
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
inline void println(){cout<<"\n";}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R>
void debug_(F f,R... r){int bc=0;while (bc != 0 || dnms_[di_] != ','){if (dnms_[di_] == '(') {bc++;}else if (dnms_[di_] == ')') {bc--;}cout << dnms_[di_++];}di_++;cout << ": " << f << ",";debug_(r...);}
#define debug(...) do{dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__);}while(0)
#pragma endregion

// Typedefs
const int MN = 1000;

struct p {
    int v, id;
    bool operator<(const p &o) const {
        return v > o.v;
    }
};

int n;
p arr[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(n);

    for (int i = 0; i < n; i++) {
        scan(arr[i].v);
        arr[i].id = i;
    }

    sort(arr, arr + n);

    ll tot = 0;
    FORI(0, n) {
        tot += i * arr[i].v + 1;
    }

    println(tot);
    FORI(0, n) {
        print(arr[i].id + 1, ' ');
    }
    print('\n');

    return 0;
}