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

int n, res;
int arr[2010];
set <int> st;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] < 0)
			arr[i] *= -1;
		st.insert(arr[i]);
	}
	int tot = 0;
	for(set <int>::iterator it = st.begin(); it != st.end(); it++){
		int x = *it;
		int cnt = 0, now = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] < x)
				cnt++;
			if(arr[i] == x){
				now++;
				res += min(cnt, tot - cnt);
			}
		}
		tot += now;
	}
	cout << res << endl;
	return 0;
}