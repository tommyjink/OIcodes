#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define intl long long
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
    intl x=0,k=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch == '-') k=-1;ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*k;
}
intl n, a[N];
int main() {
    // freopen("shelf.in","r",stdin);
    // freopen("shelf.out","w",stdout);
    n = read();
    For(i,1,n) a[i] = read();
    intl ans = 0, now = 1;
    For(i,1,n) if(a[i] == now) ans ++, now ++;
    printf("%lld\n", n - ans);
    return 0;
}