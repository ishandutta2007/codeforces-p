#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, m;
        cin >> n >> m;
        cout << (n*m+1)/2 << "\n";
    }
    return 0;
}