#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    ll n;
    ios::sync_with_stdio(false);
    cin >> n;
    n++;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    if(n % 2 == 0) {
        cout << n / 2;
    }
    else {
        cout << n;
    }
    //cin.close();
    //cout.close();
    return 0;
}