#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int res=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(i<k && a[i]>k){res++;}
    }
    cout << res << "\n";
  }
  return 0;
}