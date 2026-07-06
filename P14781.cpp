#include<bits/stdc++.h>
#define int __int128
#define endl "\n"
using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

const long long N=1e6+10;
int n,a[N],b[N],ans=0;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int lcm(int x,int y){return x*y/gcd(x,y);}

signed main()
{
    n = read();
    for(long long i=1;i<=n;i++)
        a[i] = read();
    for(long long i=1;i<=n;i++)
        b[i] = read();
    ans=n+2+b[1];
    for(long long i=2;i<=n;i++)
    {
        int d=lcm(b[i-1],b[i]);
        a[i]*=d,a[i-1]*=d;
        int k=lcm(a[i-1]/b[i-1],a[i]/b[i]);
        ans+=b[i]-min(a[i]/k,a[i-1]/k);
        a[i]/=d,a[i-1]/=d;
    }
    print(ans);
    putchar('\n');
    return 0;
}