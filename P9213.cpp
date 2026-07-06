#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int t;
__int128 n,l,a,b;
__int128 read()
{
	__int128 res=0;
	char c[1005];
	scanf("%s",c);
	for(int i=0;i<strlen(c);i++)
	{
		res*=10;
		res+=c[i]-'0';
	}
	return res;
}
void print(__int128 num)
{
	if(num>9) 
		print(num/10);
	putchar(num%10+'0');
}
__int128 gcd(__int128 x,__int128 y)
{
    if(x<y)swap(x,y);
    return y==0?x:gcd(y,x%y);
}
__int128 lcm(__int128 x,__int128 y)
{
    return x*y/gcd(x,y);
}
signed main()
{
    // int a,b;
    // while(1)
    //     scan(a),scan(b),print(gcd(a,b));
    cin>>t;
    while(t--)
    {
        n=read(),a=read(),b=read(),
        l=(n-1)*a;
        print(l/lcm(a,b)+1);
        puts("");
    }
    return 0;
}