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
    int idx = -1;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '0'){
            idx = i;
            break;
        }
    }
    if(idx == -1)
        cout << str.substr(1) << endl;
    else cout << str.substr(0, idx) << str.substr(idx + 1) << endl;
    return 0;
}