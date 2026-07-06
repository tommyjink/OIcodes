#import<iostream>
long c,m,t,M=1e9+7,b[4];std::string s;main(){std::cin>>s>>s;for(int x:s)c|=x^s[0],m^=x&3,t-=b[m],t+=b[m]=t%M+!!m;std::cout<<(!c?:b[m]%M);}
