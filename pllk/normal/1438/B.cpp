#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        if (s.size() == n) cout << "NO\n";
        else cout << "YES\n";
    }
}