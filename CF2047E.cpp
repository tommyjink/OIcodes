#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+100;
int n,x[N],y[N],xx[N],yy[N];
int a[N],tx[N],ty[N],t[N];
vector<int> b[N];
int lowbit(int x){return x&(-x);}
void init(int x)
{
    for(int i=1;i<=x;i++)
        t[i]=0;
}
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=t[i];
    return res;
}
int ask(int x,int y)
{
    if(x<=y)return query(y)-query(x-1);
    else return 0;
}
int get
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        init(n);
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i], 
            xx[i]=x[i], 
            yy[i]=y[i];
        sort(xx+1,xx+1+n);
        sort(yy+1,yy+1+n);
        for(int i=1;i<=n;i++)
        {
            tx[i]=lower_bound(xx+1,xx+1+n,x[i])-xx;
            ty[i]=lower_bound(yy+1,yy+1+n,y[i])-yy;
            a[ty[i]]++;
            b[tx[i]].push_back(ty[i]);
        }
        for(int X=1;X<=n;X++)
        {
            for(int Y:b[X]) add(Y,1);
            int l=0,r=n/4+4;
            while(l<r)
            {
                int mid=(l+r)>>1;
                int ltop=
            }
        }
    }
    return 0;
}