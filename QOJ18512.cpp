#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
int n,k,ans;
vector<int> a,b,c,d,tmp,cn;
int cal(int l,int mid,int r)
{
    int res=0,x=l,y=mid+1,z=l;
    while(x<=mid&&y<=r)
    {
        if(c[x]<=c[y])
            tmp[z++]=c[x++];
        else
        {
            tmp[z++]=c[y++];
            res+=mid-x+1;
        }
    }
    while(x<=mid)
        tmp[z++]=c[x++];
    while(y<=r)
        tmp[z++]=c[y++];
    for(int i=l;i<=r;i++)
        c[i]=tmp[i];
    return res;
}
int msort(int l,int r)
{
    if(l>=r)return 0;
    int mid=(l+r)>>1,res=0;
    res+=msort(l,mid);
    res+=msort(mid+1,r);
    res+=cal(l,mid,r);
    return res;
}
void solve()
{
    cin>>n>>k;
    a.assign(n*k,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
        {
            cin>>a[i*k+j];
            a[i*k+j]--;
        }
    b.assign(k,0);
    c.assign(k,0);
    d.assign(k,0);
    tmp.assign(k,0);
    ans=0;
    if(n<k)
    {
        for(int l=0;l<n;l++)
        {
            for(int i=0;i<k;i++)
                b[i]=i;
            for(int r=l;r<n;r++)
            {
                for(int i=0;i<k;i++)
                    c[i]=b[a[r*k+i]];
                for(int i=0;i<k;i++)
                    b[i]=c[i];
                ans+=msort(0,k-1);
            }
        }
        cout<<ans<<endl;
    }
    else
    {
        cn.assign(k*k,0);
        for(int i=0;i<k;i++)
            b[i]=d[i]=i;
        for(int r=0;r<n;r++)
        {
            for(int i=0;i<k;i++)
                d[b[i]]=i;
            for(int i=0;i<k;i++)
                for(int j=0;j<k;j++)
                    if(d[i]>d[j])cn[i*k+j]++;
            for(int i=0;i<k;i++)
                c[i]=b[a[r*k+i]];
            for(int i=0;i<k;i++)
                b[i]=c[i];
            for(int i=0;i<k;i++)
                for(int j=i+1;j<k;j++)
                    ans+=cn[b[i]*k+b[j]];
        }
        cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
