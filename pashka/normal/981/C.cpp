#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        d[x - 1]++;
        d[y - 1]++;
    }
    vector<int> ones;
    vector<int> big;
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            ones.push_back(i + 1);
        }
        if (d[i] > 2) {
            big.push_back(i + 1);
        }
    }
    if (big.size() > 1) {
        cout << "No\n";
    } else if (big.size() == 0) {
        cout << "Yes\n";
        cout << "1\n";
        cout << ones[0] << " " << ones[1] << "\n";
    } else {
        cout << "Yes\n";
        cout << ones.size() << "\n";
        for (auto one : ones) {
            cout << one << " " << big[0] << "\n";
        }
    }

    return 0;
}