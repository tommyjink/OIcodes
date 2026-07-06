#include<bits/stdc++.h>
int p,l,r;std::string s,t=" tongji";main(){std::cin>>s>>s;for(char c:s){if(c!=t[p]&&c!=t[p+1])p=r=0;p+=(c==t[p+1]),r+=(p==1);if(p==6)l+=r;}std::cout<<l;}