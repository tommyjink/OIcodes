#include<algorithm>
#include<iostream>
int a[105][105];
main(){int t,n,m;for(std::cin>>t;t--;){m=0;for(std::cin>>n;std::cin.get()&&n--;){n++;for(int i=1;i<=n;++i)std::cin>>a[n][i],a[n][i]+=std::max(a[n-1][i],a[n-1][i-1]),m=std::max(m,a[n][i]);}std::cout<<m<<'\n';}}