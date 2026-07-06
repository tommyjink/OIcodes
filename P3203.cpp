#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],len,st[N],ed[N],id[N],f[N],s[N];
void update(int i)
{
    for(int j=ed[i];j>=st[i];j--)
    {
        if(j+a[j]>ed[i])f[j]=1,s[j]=j+a[j];
        else f[j]=f[j+a[j]]+1,s[j]=s[j+a[j]];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    len=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        id[i]=(i-1)/len+1;
        // cout<<id[i]<<" ";
        if(id[i]!=id[i-1])
        {
            st[id[i]]=i;
            ed[id[i-1]]=i-1;
        }
    }
    // cout<<endl;
    ed[id[n]]=n;
    int m=id[n];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)update(i);
    // for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<s[i]<<" ";
    // cout<<endl;
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        // cout<<"ok"<<endl;
        if(op==1)
        {
            int x,res=0;
            cin>>x;
            x++;
            while(x<=n)
            {
                res+=f[x];
                x=s[x];
            }
            cout<<res<<endl;
        }
        else
        {
            int x,y;
            cin>>x>>y;
            x++;
            a[x]=y;
            update(id[x]);
        }
    }
    return 0;
}