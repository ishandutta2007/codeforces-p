                                       /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL
//#define cin fin
//#define cout fout

int r, c;
set <char> st[110];

int main(){
	cin >> r >> c;
	string str;
	for(int i = 0; i < r; i++){
		cin >> str;
		for(int j = 0; j < c; j++)
			st[j].insert(str[j]);
	}
	int64 res = 1;
	for(int i = 0; i < c; i++)
		res = (res * st[i].size()) % Mod;
	cout << res << endl;
    return 0;
}