#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;


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


inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

const int N=1e6+10,P=1e9+7,L=1000;
int n,a[N];
long b[200005][200];
int m=0,ans[N],inv[N],num[N];
int prime[N],cnt=0,phi[N],vis[N];
int id[N],len=0,now=1,tot=0,v[N],tag[N];

struct node
{
    int l,r,id;
}c[N];

inline bool cmp(node &x,node &y)
{
    if(id[x.l]!=id[y.l])return id[x.l]<id[y.l];
    else if(id[x.l]&1)return x.r<y.r;
    else return x.r>y.r;
}

inline void init()
{
    phi[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])prime[++cnt]=i,num[i]=cnt,phi[i]=i-1;
        for(int j=1;j<=cnt;j++)
        {
            if(prime[j]*i>=N)break;
            vis[i*prime[j]]=prime[j];
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
    inv[1] = 1;
    for(int i=2;i<N;i++)
        inv[i] = (P - P / i) * inv[P % i] % P;
}

inline int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}

inline void add(int x)
{
    if(v[a[x]]==1)return;
    if(!tag[a[x]])now=now*(v[a[x]]-1)%P;
    else now=now*v[a[x]]%P;
    tag[a[x]]++;
}

inline void del(int x)
{
    if(v[a[x]]==1)return;
    tag[a[x]]--;
    if(!tag[a[x]]) now=now*inv[v[a[x]]-1]%P;
    else now=now*inv[v[a[x]]]%P;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init(); 
    
    n = read();
    len=1220;
    for(int i=1;i<=n;i++)
    {
        id[i]=(i-1)/len+1;
        a[i] = read();
        while(vis[a[i]])b[i][num[vis[a[i]]]]++,a[i]/=vis[a[i]];
        if(a[i]<=L)b[i][num[a[i]]]++,a[i]=1;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;prime[j]<=L;j++)
            b[i][j]=(b[i][j]+b[i-1][j]);
    
    for(int i=1;i<=n;i++)
        v[i]=a[i];
    sort(v+1,v+1+n);
    tot=unique(v+1,v+1+n)-v-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(v+1,v+1+tot,a[i])-v;
    
    int q = read();
    for(int j=1;j<=q;j++)
    {
        ans[j]=1;
        int l = read(), r = read();
        c[j].l=l,c[j].r=r;
        c[j].id=j;
        for(int i=1;prime[i]<=L;i++)
        {
            int k=b[r][i]-b[l-1][i];
            if(!k)continue;
            if(k==1)ans[j]=(ans[j]*(prime[i]-1))%P;
            else
            {
                int pk = qpow(prime[i], k);
                int pk_1 = qpow(prime[i], k-1);
                ans[j]=((pk - pk_1) % P + P) % P * ans[j] % P;
            }
        }
    }
    
    sort(c+1,c+1+q,cmp);
    int l=1,r=0;
    for(int i=1;i<=q;i++)
    {
        while(l<c[i].l)del(l++);
        while(l>c[i].l)add(--l);
        while(r<c[i].r)add(++r);
        while(r>c[i].r)del(r--);
        ans[c[i].id]=ans[c[i].id]*now%P;
    }
    
    for(int i=1;i<=q;i++)
    {
        write(ans[i]);
        putchar('\n');
    }
    
    return 0;
}