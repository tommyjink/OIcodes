#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,v,a[N],s[N],f[N],t[N],b[N],p[1000][30],mp[N];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
int cal(int x,int y)
{
    int res=x;
    for(int i=20;i>=0;i--)
    {
        if(y>=(1ll<<i))
        {
            y-=(1ll<<i);
            res=p[res][i];
        }
    }
    return res+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>v;
    for(int i=0;i<v;i++)
        p[i][0]=i*i*i%v;
    for(int i=1;i<=25;i++)
        for(int j=0;j<v;j++)
            p[j][i]=p[p[j][i-1]][i-1];
    for(int i=0;i<=15;i++)
        f[(1ll<<i)]=i;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(m--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1)
        {
            int len=r-l+1;
            if(len>=14)
            {
                cout<<"Yuno"<<endl;
                continue;
            }
            s[0]=0;
            for(int i=l;i<=r;i++)
            {
                int now=query(i);
                b[i]=cal(a[i],now);
            }
            for(int i=0;i<=v*len;i++)
                mp[i]=0;
            for(int i=1;i<(1ll<<len);i++)
            {
                s[i]=s[i^lowbit(i)]+b[l+f[lowbit(i)]];
                if(mp[s[i]])
                {
                    cout<<"Yuno"<<endl;
                    break;
                }
                mp[s[i]]=1;
                if(i==(1ll<<len)-1)cout<<"Yuki"<<endl;
            }
        }
        else add(l,1),add(r+1,-1);
    }
    return 0;
}