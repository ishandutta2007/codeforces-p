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
#define PLL pair<int64, int64>

int main(){
    string str;
    cin >> str;
    int a = 0, b = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '4') a++;
        if(str[i] == '7') b++;
    }
    if(b > a) cout << 7 << endl;
    else if(a == 0) cout << -1 << endl;
    else cout << 4 << endl;
    return 0;
}