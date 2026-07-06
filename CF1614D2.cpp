#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e7+10;
int n,a[N],num[M],m=0,tag[M];
long long f[M];
int p[M],cnt=0;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    n = read();
    for(int i=1;i<=n;i++)
    {
        a[i] = read();
        if(a[i]>m) m=a[i];
        
        int l=sqrt(a[i]);
        for(int j=1;j<=l;j++)
        {
            if(a[i]%j==0)
            {
                num[j]++;
                if(j*j!=a[i]) num[a[i]/j]++;
            }
        }
    }
    
    for(int i=2;i<=m;i++)
    {
        if(!tag[i]) p[cnt++]=i;
        for(int j=0;j<cnt;j++)
        {
            int k=i*p[j];
            if(k>m) break;
            tag[k]=true;
            if(i%p[j]==0) break;
        }
    }
    
    long long ans=0;
    for(int i=m;i>=1;i--)
    {
        if(num[i]==0)continue;
        f[i]=1ll*i*(1ll*num[i]);
        for(int j=0;j<cnt;j++)
        {
            long long k=i*p[j];
            if(k>m) break;
            f[i]=max(f[i],f[k]+1ll*(1ll*i)*(1ll*(num[i]-num[k])));
        }
        ans=max(ans,f[i]);
    }
    
    write(ans);
    putchar('\n');

    return 0;
}