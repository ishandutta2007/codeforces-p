#include<bits/stdc++.h>
using namespace std;int n,a[1000005];int main(){cin>>n;for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<19;i++){for(int j=0;j<n;j++){if(j&(1<<i))a[j]^=a[j^(1<<i)];}}for(int i=0;i<19;i++){for(int j=0;j<n;j++){if(j&(1<<i))a[j^(1<<i)]^=a[j];}}for(int i=n-1;i>=0;i--)cout<<a[i]<<" ";return 0;}