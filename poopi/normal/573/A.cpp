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

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n;
int arr[100010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		while(arr[i] % 2 == 0)
			arr[i] /= 2;
		while(arr[i] % 3 == 0)
			arr[i] /= 3;
	}
	string res = "Yes";
	for(int i = 1; i < n; i++)
		if(arr[i] != arr[i - 1])
			res = "No";
	cout << res << endl;
	return 0;
}