#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m,a;
  cin >> n >> m >> a;
  cout << llceil(n,a)*llceil(m,a) << '\n';
  return 0;
}