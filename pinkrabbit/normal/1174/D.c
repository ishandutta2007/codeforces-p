main(n,q,k,i){scanf("%d%d",&n,&k),n=1<<n,printf("%d ",(n>>(k<n))-1),q=i=0;while(++i<n)if(i<(i^k))printf("%d ",i^q),q=i;}