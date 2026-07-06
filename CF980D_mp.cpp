#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
#define F(x) ((x)*(x))
using namespace std;
const int N=5005,P=1e9+7;
int n,a[N],ans[N],fa[N],c[N];
int getfa(int x)
{
    if(x==fa[x])return x;
    else return (fa[x]=getfa(fa[x]));
}
void merge(int x,int y)
{
    x=getfa(x),y=getfa(y);
    if(x!=y)fa[x]=y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i]*a[j]>0)
            {
                if(a[i]*a[j]==F((int)sqrt(a[i]*a[j])))merge(i,j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=i;j<=n;j++)
        {
            if(a[j]==0)ans[max(1ll,now)]++;
            else
            {
                if(!c[getfa(j)])now++,c[getfa(j)]=1;
                ans[now]++;
            }
        }
        for(int j=i;j<=n;j++)
            c[getfa(j)]=0;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}