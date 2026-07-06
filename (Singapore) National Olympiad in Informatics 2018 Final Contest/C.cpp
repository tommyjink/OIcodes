#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int n,fa[N],x[N],y[N],tag[N];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void merge(int x,int y){fa[getfa(x)]=fa[getfa(y)];}
inline int cal(int x,int y,int xx)
{
    return y-abs(x-xx);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int now=1;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i],fa[i]=i;
    for(int i=1;i<=n;i++)
        if(y[i]<=cal(x[now],y[now],x[i]))
            merge(i,now);
        else now=i;
    for(int i=1;i<=n;i++)
    {
        if(i==fa[i])tag[i]++;
        fa[i]=i;
    }
    now=n;
    for(int i=n;i>=1;i--)
        if(y[i]<=cal(x[now],y[now],x[i]))
            merge(i,now);
        else now=i;
    int ans=0;
    for(int i=1;i<=n;i++)
        if(i==fa[i]&&tag[i])ans++;
    cout<<ans<<endl;
    return 0;
}