#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    int v=(1<<30)-1;
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(a[i]!=i){v&=a[i];}
    }
    cout << v << '\n';
  }
  return 0;
}