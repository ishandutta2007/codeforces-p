/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

class AOcharovannieIgroi {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int a, b;
	    in >> a >> b;
	    vector<bool> can(a + b + 1);
	    for (int first = 0; first < 2; ++first) {
	        vector<int> cnt(2);
	        for (int i = 0; i < a + b; ++i) {
	            ++cnt[(i + first) % 2];
	        }
	        for (int f = 0; f <= cnt[0] && f <= a; ++f) {
	            int o = a - f;
	            if (o <= cnt[1]) {
	                can[cnt[0] - f + o] = true;
	            }
	        }
	    }
	    int m = 0;
	    for (int i = 0; i < can.size(); ++i) if (can[i]) ++m;
	    out << m << "\n";
	    for (int i = 0; i < can.size(); ++i) if (can[i]) out << i << " ";
	    out << "\n";
	}
};


int main() {
	AOcharovannieIgroi solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}