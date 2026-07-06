#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=1e6+10;

int q,c,len[3];
int opt[N],xx[N],yy[N];
int rtr[N],ctr[N],rval[N],cval[N],rtim[N],ctim[N],rp[N],cp[N];

inline void init(int tr[],int n)
{
    for(int i=1;i<=n;i++)tr[i]=i&-i;
}

inline void add(int tr[],int n,int x,int v)
{
    for(;x<=n;x+=x&-x)tr[x]+=v;
}

inline int kth(int tr[],int n,int k)
{
    int p=0;
    for(int i=1<<20;i;i>>=1)
    {
        if(p+i<=n&&tr[p+i]<k)
        {
            k-=tr[p+i];
            p+=i;
        }
    }
    return p+1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>q>>c;
    len[1]=len[2]=1;
    for(int i=1;i<=q;i++)
    {
        cin>>opt[i]>>xx[i]>>yy[i];
        if(opt[i]<=2)len[opt[i]]++;
    }
    init(rtr,len[1]);
    init(ctr,len[2]);
    for(int i=q;i>=1;i--)
    {
        if(opt[i]==1)
        {
            int p=kth(rtr,len[1],xx[i]+1);
            rval[p]=yy[i];
            rtim[p]=i;
            add(rtr,len[1],p,-1);
        }
        else if(opt[i]==2)
        {
            int p=kth(ctr,len[2],xx[i]+1);
            cval[p]=yy[i];
            ctim[p]=i;
            add(ctr,len[2],p,-1);
        }
        else
        {
            rp[i]=kth(rtr,len[1],xx[i]);
            cp[i]=kth(ctr,len[2],yy[i]);
        }
    }
    int p=kth(rtr,len[1],1);
    rval[p]=c;
    p=kth(ctr,len[2],1);
    cval[p]=c;
    for(int i=1;i<=q;i++)
        if(opt[i]==3)
        {
            if(rtim[rp[i]]>ctim[cp[i]])cout<<rval[rp[i]]<<endl;
            else cout<<cval[cp[i]]<<endl;
        }
    return 0;
}
